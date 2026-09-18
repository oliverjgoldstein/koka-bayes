module core/finite

import std/num/float64
import core/dist
import core/obsvalue

pub struct finite-choice
  value           : observable
  log-probability : float64

// Enumerate only positive-mass outcomes. The support budget is checked before
// allocating the returned population, including for very large Binomial counts.
// Probabilities stay in log space: an extremely small but positive category must
// remain available even when converting its probability to float64 would be zero.
pub fun finite-support(distribution : dist, max-size : int) : <div,exn> list<finite-choice>
  if max-size <= 0
    then throw("Finite support needs a positive support budget.")
    elif not(is-valid(distribution))
      then throw("Invalid distribution parameters: " ++ distribution.summary)
    else
      match distribution.primitive
        PBernoulli(probability) ->
          if probability == 0.0
            then [Finite-choice(ObsBool(False), 0.0)]
            elif probability == 1.0
              then [Finite-choice(ObsBool(True), 0.0)]
            else
              check-size(2, max-size)
              [Finite-choice(ObsBool(False), ln1p(~probability)),
               Finite-choice(ObsBool(True), ln(probability))]
        PDiscrete(weights) ->
          val count = weights.foldl(0, fn(acc, weight){ if weight > 0.0 then acc + 1 else acc })
          check-size(count, max-size)
          normalize-support(categorical-support(weights, 0))
        PBinomial(count, probability) ->
          if count == 0 || probability == 0.0
            then [Finite-choice(ObsInt(0), 0.0)]
            elif probability == 1.0
              then [Finite-choice(ObsInt(count), 0.0)]
            else
              check-size(count + 1, max-size)
              val log-failure = ln1p(~probability)
              val log-odds = ln(probability) - log-failure
              normalize-support(binomial-support(count, 0, float64(count) * log-failure, log-odds))
        PPoisson(rate) ->
          if rate == 0.0 then [Finite-choice(ObsInt(0), 0.0)]
          else unsupported(distribution)
        _ -> unsupported(distribution)

fun check-size(size : int, maximum : int) : exn ()
  if size > maximum then
    throw("Finite support exceeds its budget: " ++ size.show ++ " outcomes; limit " ++ maximum.show ++ ".")

fun unsupported(distribution : dist) : exn list<finite-choice>
  throw("Exact enumeration requires finite discrete latent support; unsupported " ++ distribution.summary)

fun categorical-support(weights : list<float64>, index : int) : list<finite-choice>
  match weights
    Nil -> []
    Cons(weight, rest) ->
      if weight > 0.0
        then Cons(Finite-choice(ObsInt(index), ln(weight)), categorical-support(rest, index + 1))
        else categorical-support(rest, index + 1)

// P(k+1)/P(k) = ((n-k)/(k+1)) * p/(1-p), evaluated with logarithms.
// This constructs all n+1 log masses in O(n), without factorials or Gamma calls.
// The final normalization removes accumulated common rounding error.
fun binomial-support(count : int, index : int, log-mass : float64,
                       log-odds : float64) : div list<finite-choice>
  val current = Finite-choice(ObsInt(index), log-mass)
  if index == count
    then [current]
    else
      val next = log-mass + ln(float64(count - index)) - ln(float64(index + 1)) + log-odds
      Cons(current, binomial-support(count, index + 1, next, log-odds))

fun normalize-support(choices : list<finite-choice>) : list<finite-choice>
  val largest = choices.foldl(neginf, fn(acc, choice){ max(acc, choice.log-probability) })
  val scaled-total = choices.foldl(0.0, fn(acc, choice){ acc + exp(choice.log-probability - largest) })
  val log-scale = ln(scaled-total)
  choices.map(fn(choice){
    Finite-choice(choice.value, (choice.log-probability - largest) - log-scale)
  })
