module enumeration_checks

import bayes
import alg/enumerate
import core/trace
import std/num/random

val y = obs-bool("enumeration/y")
val reading = obs-float64("enumeration/reading")

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun near(actual : float64, expected : float64) : bool
  is-finite(actual) && abs(actual - expected) <= 1.0e-11 * max(1.0, abs(expected))

fun fails(action : () -> <exn|e> a) : e bool
  try(fn(){ val result = action(); False }, fn(_exception){ True })

fun two-coins() : model-dist int
  val first = bernoulli'(0.5)
  val second = bernoulli'(0.5)
  (if first then 1 else 0) + (if second then 1 else 0)

fun stochastic-loop() : <model-dist,div> ()
  val ignored = bernoulli'(0.5)
  stochastic-loop()

fun test-two-coins() : <div,exn> ()
  val result = enumerate(empty(), two-coins)
  ensure("two coins visit all four complete paths", result.executions == 4 && result.outcomes.length == 4)
  ensure("two coins count distribution operations and resumed alternatives", result.nodes == 9)
  ensure("two coins integrate to unit mass", near(result.log-evidence, 0.0))
  [0, 1, 2].foreach fn(heads){
    ensure("two-coin posterior matches the full binomial distribution",
      near(probability(result, fn(value){ value == heads }), if heads == 1 then 0.5 else 0.25))
  }
  ensure("two-coin expected head count is one", near(expectation(result, float64), 1.0))
  ensure("predicate probability need not match an individual value", near(probability(result, fn(value){ value >= 1 }), 0.75))
  ensure("an impossible event under a valid posterior has probability zero", probability(result, fn(value){ value == 3 }) == 0.0)
  val merged = marginal(result, fn(left, right){ left == right })
  ensure("marginal merges equal values from distinct paths", merged.length == 3)
  merged.foreach fn(item){
    val expected = if item.value == 1 then 0.5 else 0.25
    ensure("marginal probabilities include duplicate return values", near(item.probability, expected) && near(item.log-probability, ln(expected)))
  }
  result.outcomes.foreach fn(outcome){
    ensure("coin paths have exact prior and posterior mass", near(outcome.log-weight, ln(0.25)) && near(outcome.probability, 0.25) && near(outcome.log-probability, ln(0.25)))
    ensure("coin branches keep independent traces", outcome.trace.length == 2 && sampled-addresses(outcome.trace) == [0, 1])
    ensure("coin traces agree with path joint mass", near(total-log-prob(outcome.trace), outcome.log-weight))
  }

fun test-informative-bayes() : <div,exn> ()
  // Independent two-cell oracle: .3*.8=.24 and .7*.2=.14.
  val result = enumerate(singleton(y, [True]), fn(){
    val cause = bernoulli'(0.3)
    val observed = bernoulli(y, if cause then 0.8 else 0.2)
    cause
  })
  ensure("Bayes model has two latent execution paths", result.outcomes.length == 2)
  ensure("Bayes evidence includes the latent prior", near(exp(result.log-evidence), 0.38))
  ensure("Bayes posterior is 12/19", near(probability(result, fn(cause){ cause }), 12.0/19.0))
  result.outcomes.foreach fn(outcome){
    ensure("Bayes outcome joint weights are unnormalized", near(exp(outcome.log-weight), if outcome.value then 0.24 else 0.14))
    ensure("Bayes traces distinguish sampled and observed sites", outcome.trace.length == 2 && sampled-addresses(outcome.trace) == [0])
    ensure("observations remain fixed in every branch", get(y, outcome.output-env) == [True])
    ensure("Bayes trace density agrees with enumeration", near(total-log-prob(outcome.trace), outcome.log-weight))
  }

fun test-categorical-binomial() : <div,exn> ()
  // Mix Binomial(2,1/4) with weight1/3 and Binomial(2,3/4) with weight2/3.
  // Its masses for counts 0,1,2 are [11,18,19]/48.
  val result = enumerate(empty(), fn(){
    val category = discrete'([1.0, 2.0])
    binomial'(2, if category == 0 then 0.25 else 0.75)
  })
  ensure("categorical/binomial enumerates all six paths", result.executions == 6 && result.outcomes.length == 6)
  zip([0, 1, 2], [11.0/48.0, 18.0/48.0, 19.0/48.0]).foreach fn(item){
    ensure("categorical/binomial full posterior equals finite arithmetic",
      near(probability(result, fn(value){ value == fst(item) }), snd(item)))
  }
  ensure("categorical/binomial expectation matches mixture means", near(expectation(result, float64), 7.0/6.0))
  val sparse = enumerate(empty(), fn(){ discrete'([0.0, 2.0, 0.0, 3.0]) })
  ensure("zero categorical alternatives are never returned", sparse.outcomes.length == 2 && sparse.outcomes.all(fn(item){ item.value == 1 || item.value == 3 }))
  ensure("categorical normalization preserves indices", near(probability(sparse, fn(value){ value == 1 }), 0.4))
  [1.0e308, 1.0e-300].foreach fn(scale){
    val stable = enumerate(empty(), fn(){ discrete'([scale, scale]) })
    ensure("categorical normalization handles extreme finite weights", near(probability(stable, fn(value){ value == 0 }), 0.5))
    stable.outcomes.foreach fn(item){ ensure("extreme categorical trace agrees with enumeration", near(total-log-prob(item.trace), item.log-weight)) }
  }
  val revived = enumerate(empty(), fn(){
    val category = discrete'([1.0e308, 1.0e-308])
    log-score(if category == 1 then 616.0 * ln(10.0) else 0.0)
    category
  })
  ensure("a log factor can revive a prior path below floating underflow", revived.outcomes.length == 2 && near(probability(revived, fn(value){ value == 1 }), 0.5) && near(exp(revived.log-evidence), 2.0))
  revived.outcomes.foreach fn(item){ ensure("revived rare path has consistent finite trace density", near(total-log-prob(item.trace), item.log-weight) && near(item.log-weight, 0.0)) }
  val rare-tail = enumerate(empty(), fn(){ discrete'([1.0e308, 1.0e-308]) })
  val tail-mean = expectation(rare-tail, fn(category){ if category == 1 then 1.0e308 else 0.0 })
  val negative-tail-mean = expectation(rare-tail, fn(category){ if category == 1 then ~1.0e308 else 0.0 })
  ensure("expectation retains contributions whose posterior probability underflows", tail-mean > 0.0 && abs(tail-mean / 1.0e-308 - 1.0) < 1.0e-10)
  ensure("signed expectation retains negative underflow-tail contributions", negative-tail-mean < 0.0 && abs(negative-tail-mean / ~1.0e-308 - 1.0) < 1.0e-10)
  val deterministic = enumerate(empty(), fn(){
    val certain = bernoulli'(1.0)
    val empty-binomial = binomial'(0, 0.25)
    val no-count = poisson'(0.0)
    (certain, empty-binomial, no-count)
  })
  ensure("finite degenerate distributions have one path", deterministic.outcomes.length == 1 && deterministic.executions == 1 && near(deterministic.log-evidence, 0.0))
  deterministic.outcomes.foreach fn(item){ ensure("finite degenerate values are correct", item.value == (True, 0, 0)) }

fun test-observation-branches() : <div,exn> ()
  // One branch consumes all three data; the other consumes two. The cursor
  // after the shared first observation must be copied for each resumption.
  val result = enumerate(singleton(y, [True, False, True]), fn(){
    val first = bernoulli(y, 0.6)
    val selected = bernoulli'(0.5)
    if selected then
      val middle = bernoulli(y, 0.8)
      val last = bernoulli(y, 0.7)
      ensure("true branch uses its own remaining observations", first && not(middle) && last)
    else
      val last = bernoulli(y, 0.3)
      ensure("false branch uses its own remaining observations", first && not(last))
    selected
  })
  ensure("branching evidence is .042 + .21", near(exp(result.log-evidence), 0.252))
  ensure("branching posterior is one sixth", near(probability(result, fn(value){ value }), 1.0/6.0))
  result.outcomes.foreach fn(item){
    val expected-data = if item.value then [True, False, True] else [True, False]
    val expected-addresses = if item.value then [0, 1, 2, 3] else [0, 1, 2]
    ensure("branch outputs include only that branch's observations", get(y, item.output-env) == expected-data)
    ensure("branch trace addresses preserve their common prefix", item.trace.map(fn(entry){ entry.address }) == expected-addresses)
    ensure("branch trace density agrees with joint weight", near(total-log-prob(item.trace), item.log-weight))
  }
  val exhausted = enumerate(singleton(y, [True]), fn(){
    val first = bernoulli(y, 0.6)
    val second = bernoulli(y, 0.25)
    (first, second)
  })
  ensure("exhausted observation streams become latent finite choices", exhausted.outcomes.length == 2 && near(exp(exhausted.log-evidence), 0.6))
  ensure("exhausted stream posterior is the next draw's prior", near(probability(exhausted, fn(value){ snd(value) }), 0.25))

fun test-observed-continuous() : <div,exn> ()
  val result = enumerate(singleton(reading, [0.0]), fn(){
    val category = discrete'([0.2, 0.8])
    val datum = normal(reading, if category == 0 then 0.0 else 2.0, 1.0)
    category
  })
  val phi0 = 1.0 / sqrt(2.0*pi)
  val z = phi0 * (0.2 + 0.8 * exp(~2.0))
  ensure("continuous observed likelihoods contribute density evidence", near(exp(result.log-evidence), z))
  ensure("continuous data update a discrete posterior exactly", near(probability(result, fn(value){ value == 0 }), 0.2 / (0.2 + 0.8 * exp(~2.0))))
  ensure("continuous observations are not enumerated as latents", result.outcomes.length == 2 && result.outcomes.all(fn(item){ sample-count(item.trace) == 1 && get(reading, item.output-env) == [0.0] }))
  val count-data = obs-int("enumeration/count")
  val count-observed = enumerate(singleton(count-data, [2]), fn(){ poisson(count-data, 1.5) })
  ensure("infinite-support distributions may still be observed", count-observed.outcomes.length == 1 && near(exp(count-observed.log-evidence), exp(~1.5)*1.5*1.5/2.0))

fun nested-model(push : bool) : <model-dist,div,exn> bool
  val selected = bernoulli'(0.5)
  val inner = enumerate(singleton(y, [True]), fn(){ bernoulli(y, if selected then 0.8 else 0.2) })
  if push then log-score(inner.log-evidence)
  selected

fun test-nested-enumeration() : <div,exn> ()
  val isolated = enumerate(empty(), fn(){ nested-model(False) })
  val pushed = enumerate(empty(), fn(){ nested-model(True) })
  ensure("nested enumeration does not silently score its evidence", near(probability(isolated, fn(value){ value }), 0.5) && near(isolated.log-evidence, 0.0))
  ensure("explicit evidence passing conditions the outer posterior", near(probability(pushed, fn(value){ value }), 0.8) && near(exp(pushed.log-evidence), 0.5))
  ensure("nested traces stay private", isolated.outcomes.all(fn(item){ item.trace.length == 1 && get(y, item.output-env).is-empty }))
  ensure("explicit evidence contributes one factor", pushed.outcomes.all(fn(item){ item.trace.length == 2 && sample-count(item.trace) == 1 && get(y, item.output-env).is-empty }))
  val reader = enumerate(singleton(y, [True, False]), fn(){
    val first = bernoulli(y, 0.6)
    val inner = enumerate(singleton(y, [False]), fn(){ bernoulli(y, 0.2) })
    val last = bernoulli(y, 0.3)
    ensure("nested reader uses separate data", near(exp(inner.log-evidence), 0.8))
    (first, last)
  })
  ensure("nested enumeration preserves outer reader and likelihood", near(exp(reader.log-evidence), 0.42) && reader.outcomes.all(fn(item){ item.value == (True, False) && item.trace.length == 2 && get(y, item.output-env) == [True, False] }))

effect branch
  ctl choose-branch() : bool

fun both(action : () -> <branch|e> a) : e list<a>
  handle(action)
    return(value) [value]
    ctl choose-branch()
      val first = resume(True)
      val second = resume(False)
      first ++ second

fun test-outer-resumptions() : <div,exn> ()
  val branches = both(fn(){
    enumerate(singleton(y, [True, False]), fn(){
      val first = bernoulli(y, 0.6)
      val selected = choose-branch()
      val latent = bernoulli'(if selected then 0.8 else 0.2)
      val last = bernoulli(y, 0.3)
      (selected, latent, first, last)
    })
  })
  ensure("enclosing multishot handler obtains both complete enumerations", branches.length == 2)
  branches.foreach fn(result){
    ensure("enclosing resumptions preserve independent evidence and paths", result.outcomes.length == 2 && near(exp(result.log-evidence), 0.42))
    result.outcomes.foreach fn(item){
      val (selected, latent, first, last) = item.value
      ensure("enclosing resumptions restore each trace and observation cursor", first && not(last) && item.trace.map(fn(entry){ entry.address }) == [0, 1, 2])
      val expected = if selected then (if latent then 0.8 else 0.2) else (if latent then 0.2 else 0.8)
      ensure("enclosing resumptions restore branch probabilities", near(item.probability, expected))
    }
  }

fun test-factors-and-empty() : <div,exn> ()
  val stable = enumerate(empty(), fn(){
    val selected = bernoulli'(0.25)
    log-score(~1000.0)
    score(if selected then 2.0 else 1.0)
    selected
  })
  ensure("enumeration normalizes below floating probability underflow", near(stable.log-evidence, ~1000.0 + ln(1.25)) && near(probability(stable, fn(value){ value }), 0.4))
  [~1.0e20, 1.0e20].foreach fn(offset){
    val shifted = enumerate(empty(), fn(){
      val selected = bernoulli'(0.5)
      log-score(offset)
      selected
    })
    ensure("large common log offsets preserve normalized posterior mass", shifted.outcomes.all(fn(item){ near(item.probability, 0.5) && near(item.log-probability, ln(0.5)) }) && near(probability(shifted, fn(_){ True }), 1.0))
  }
  val impossible = enumerate(singleton(y, [True]), fn(){ bernoulli(y, 0.0) })
  ensure("impossible data has no posterior and zero evidence", impossible.outcomes.is-empty && impossible.log-evidence == neginf)
  ensure("probability rejects an undefined posterior", fails(fn(){ probability(impossible, fn(value){ value }) }))
  ensure("expectation rejects an undefined posterior", fails(fn(){ expectation(impossible, fn(value){ if value then 1.0 else 0.0 }) }))
  ensure("marginal rejects an undefined posterior", fails(fn(){ marginal(impossible, fn(left, right){ left == right }) }))
  val pruned = enumerate(empty(), fn(){
    val selected = bernoulli'(0.5)
    if selected then score(0.0)
    selected
  })
  ensure("zero factors remove paths without inventing uniform mass", pruned.outcomes.length == 1 && near(exp(pruned.log-evidence), 0.5) && near(probability(pruned, fn(value){ not(value) }), 1.0))
  val stopped = enumerate(empty(), fn(){
    log-score(neginf)
    normal'(0.0, 1.0)
  })
  ensure("zero mass prunes before an unsupported draw can run", stopped.outcomes.is-empty && stopped.nodes == 1 && stopped.log-evidence == neginf)

fun test-errors-and-budget() : <div,exn> ()
  val pure = enumerate(empty(), fn(){ 7 }, 1)
  ensure("pure model needs no distribution nodes", pure.nodes == 0 && pure.executions == 1 && near(expectation(pure, float64), 7.0))
  ensure("exact node budget succeeds for whole two-coin tree", enumerate(empty(), two-coins, 9).outcomes.length == 4)
  [~1, 0, 1, 5, 8].foreach fn(budget){
    ensure("whole-tree budget aborts rather than returning a truncated posterior", fails(fn(){ enumerate(empty(), two-coins, budget) }))
  }
  ensure("finite support cannot allocate past the enumeration budget", fails(fn(){ enumerate(empty(), fn(){ binomial'(1000000, 0.5) }, 10) }))
  ensure("stochastic recursion cannot escape the global node budget", fails(fn(){ enumerate(empty(), stochastic-loop, 10) }))
  ensure("continuous latent Normal is rejected", fails(fn(){ enumerate(empty(), fn(){ normal'(0.0, 1.0) }) }))
  ensure("continuous latent Uniform is rejected", fails(fn(){ enumerate(empty(), fn(){ uniform'(0.0, 1.0) }) }))
  ensure("continuous latent Gamma is rejected", fails(fn(){ enumerate(empty(), fn(){ gamma'(2.0, 1.0) }) }))
  ensure("continuous latent Beta is rejected", fails(fn(){ enumerate(empty(), fn(){ beta'(2.0, 3.0) }) }))
  ensure("positive-rate Poisson has unsupported infinite support", fails(fn(){ enumerate(empty(), fn(){ poisson'(1.0) }) }))
  ensure("untraced randomness cannot silently enter exact inference", fails(fn(){ enumerate(empty(), fn(){ random-int32() }) }))
  [~0.1, 1.1, nan].foreach fn(p){
    ensure("invalid latent probabilities are rejected", fails(fn(){ enumerate(empty(), fn(){ bernoulli'(p) }) }))
    ensure("invalid observed probabilities are rejected", fails(fn(){ enumerate(singleton(y, [True]), fn(){ bernoulli(y, p) }) }))
  }
  [[], [0.0, 0.0], [~1.0, 2.0], [posinf]].foreach fn(weights){
    ensure("invalid categorical support is rejected", fails(fn(){ enumerate(empty(), fn(){ discrete'(weights) }) }))
  }
  [nan, posinf].foreach fn(weight){
    ensure("nonfinite positive or NaN factors are rejected", fails(fn(){ enumerate(empty(), fn(){ log-score(weight) }) }))
  }
  ensure("invalid observed continuous distribution is rejected", fails(fn(){ enumerate(singleton(reading, [0.0]), fn(){ normal(reading, 0.0, 0.0) }) }))

pub fun main() : <console,div,exn> ()
  test-two-coins()
  test-informative-bayes()
  test-categorical-binomial()
  test-observation-branches()
  test-observed-continuous()
  test-nested-enumeration()
  test-outer-resumptions()
  test-factors-and-empty()
  test-errors-and-budget()
  println("Finite enumeration checks passed.")
