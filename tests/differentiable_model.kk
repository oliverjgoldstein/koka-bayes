module differentiable_model

import bayes
import autodiff/smooth
import autodiff/forward
import autodiff/reverse
import autodiff/model
import examples/gradient_inference
import examples/inference
import core/sequential

val reading = obs-float64("bridge/reading")

fun ensure(label : string, condition : bool) : exn ()
  if condition then () else throw(label)

fun close(label : string, actual : float64, expected : float64) : exn ()
  ensure(label, abs(actual - expected) <= 1.0e-10 * max(1.0, abs(expected)))

fun program() : <continuous<a>,smooth<a>> a
  val theta = normal-latent(ad-constant(0.0), ad-constant(1.0))
  for(2) fn(_){
    val observed = normal-observed(reading.name, theta, ad-constant(1.0))
    ()
  }
  theta

fun target(xs : list<a>) : smooth<a> a
  log-joint(program, xs, singleton(reading, [1.0, 2.0]))

fun missing-data(xs : list<a>) : smooth<a> a
  log-joint(program, xs, singleton(reading, [1.0]))

fun wrong-data-type(xs : list<a>) : smooth<a> a
  log-joint(program, xs, singleton(obs-bool(reading.name), [True, False]))

fun ordinary() : model<e,float64>
  fn(){
    val theta = normal'(0.0, 1.0)
    for(2) fn(_){ val observed = normal(reading, theta, 1.0); () }
    theta
  }

fun test-log-joint() : exn ()
  // Independently expand all three Normal log densities at theta=1/4.
  val exact = ~1.5 * ln(2.0 * pi) - 1.84375
  close("joint evaluation", evaluate(fn(){ target([0.25]) }), exact)
  val gradient = value-and-grad(target, [0.25])
  close("reverse joint value", gradient.value, exact)
  match gradient.partials
    [slope] -> close("prior plus both likelihood gradients", slope, 2.25)
    _ -> throw("wrong joint gradient shape")
  val directional = forward(fn(){ target([Dual(0.25, 2.0)]) })
  close("forward joint value", directional.primal, exact)
  close("forward joint direction", directional.tangent, 4.5)
  match value-and-grad(target, [1.0]).partials
    [slope] -> close("exact posterior mode", slope, 0.0)
    _ -> throw("wrong mode gradient shape")
  ensure("missing latent coordinate rejected", value-and-grad(target, []).value == neginf)
  ensure("extra latent coordinate rejected", value-and-grad(target, [1.0, 2.0]).value == neginf)
  ensure("missing observation rejected", value-and-grad(missing-data, [1.0]).value == neginf)
  ensure("wrong observation type rejected", value-and-grad(wrong-data-type, [1.0]).value == neginf)
  close("separate log-joint calls reset observation state", value-and-grad(target, [0.25]).value, exact)

fun test-probabilistic-interpretation() : <div,exn> ()
  val data = singleton(reading, [1.0, 2.0])
  val adapted = likelihood-weighting(400, data, probabilistic(program), seed=9109)
  val baseline = likelihood-weighting(400, data, ordinary(), seed=9109)
  ensure("same seeded latent draws", adapted.map(fn(x){ x.value }) == baseline.map(fn(x){ x.value }))
  ensure("same observed likelihood weights", adapted.map(fn(x){ x.log-weight }) == baseline.map(fn(x){ x.log-weight }))
  // Conditional mean is 1 and variance 1/3, independent of the implementation.
  val posterior = likelihood-weighting(5000, data, probabilistic(program), seed=9113)
  ensure("adapted model exact posterior", abs(posterior-mean(posterior) - 1.0) <= 0.06)

fun test-hierarchical-example() : exn ()
  // Seven normalized Normal factors: one prior, three latent fluctuations,
  // three observations. This checks the full four-coordinate example's score.
  val result = value-and-grad(temperature-log-joint, [21.0, 20.0, 21.0, 22.0])
  close("hierarchical log joint", result.value, ~3.5 * ln(2.0 * pi) + 2.0 * ln(2.0) - 4.625)
  match result.partials
    [average, first, second, third] ->
      close("hierarchical average gradient", average, ~0.25)
      close("hierarchical first local gradient", first, 3.0)
      close("hierarchical second local gradient", second, 0.0)
      close("hierarchical third local gradient", third, ~4.0)
    _ -> throw("wrong hierarchical gradient shape")

fun test-hierarchical-interpretations() : <div,exn> ()
  val adapted = likelihood-weighting(200, inference/observations(),
    probabilistic(temperature-program), seed=9127)
  val sequential = likelihood-weighting(200, inference/observations(),
    as-model(inference/readings.length, inference/temperature-model()), seed=9127)
  ensure("hierarchical model interpretations use the same latent draws",
    adapted.map(fn(x){ x.value }) == sequential.map(fn(x){ x.value }))
  ensure("hierarchical model interpretations use the same likelihoods",
    adapted.map(fn(x){ x.log-weight }) == sequential.map(fn(x){ x.log-weight }))

pub fun main() : <console,div,exn> ()
  test-log-joint()
  test-probabilistic-interpretation()
  test-hierarchical-example()
  test-hierarchical-interpretations()
  println("Differentiable model checks passed.")
