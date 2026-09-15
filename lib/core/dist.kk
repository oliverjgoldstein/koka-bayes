module core/dist

import std/num/float64
import std/num/random
import core/obsvalue

pub type result-kind
  DistFloat64
  DistInt
  DistBool

pub type primitive-dist
  PNormal(mean : float64, stddev : float64)
  PUniform(low : float64, high : float64)
  PBernoulli(probability : float64)
  PDiscrete(weights : list<float64>)
  PBinomial(count : int, probability : float64)
  PPoisson(rate : float64)
  PGamma(shape : float64, scale : float64)
  PBeta(alpha : float64, beta : float64)

pub struct dist
  name        : string
  summary     : string
  result-kind : result-kind
  primitive   : primitive-dist

// Invalid parameters are rejected rather than silently changing the model.
pub fun is-valid(d : dist) : bool
  match d.primitive
    PNormal(mean, stddev) -> is-finite(mean) && is-finite(stddev) && stddev > 0.0
    PUniform(low, high) -> is-finite(low) && is-finite(high) && high > low
    PBernoulli(p) -> valid-probability(p)
    PDiscrete(weights) ->
      not(weights.is-empty) && weights.all(fn(w){ is-finite(w) && w >= 0.0 }) && weights.any(fn(w){ w > 0.0 })
    PBinomial(count, p) -> count >= 0 && valid-probability(p)
    PPoisson(rate) -> is-finite(rate) && rate >= 0.0
    PGamma(shape, scale) -> is-finite(shape) && is-finite(scale) && shape > 0.0 && scale > 0.0
    PBeta(alpha, beta) -> is-finite(alpha) && is-finite(beta) && alpha > 0.0 && beta > 0.0

fun valid-probability(p : float64) : bool
  is-finite(p) && p >= 0.0 && p <= 1.0

pub fun sample(d : dist) : <div,random> observable
  if not(is-valid(d))
    then impossible("invalid distribution parameters: " ++ d.summary)
    else sample-valid(d.primitive)

fun sample-valid(primitive : primitive-dist) : <div,random> observable
  match primitive
    PNormal(mean, stddev) ->
      ObsFloat64(mean + (stddev * standard-normal()))
    PUniform(low, high) ->
      ObsFloat64(low + ((high - low) * random-float64()))
    PBernoulli(probability) ->
      ObsBool(random-float64() < probability)
    PDiscrete(weights) ->
      ObsInt(sample-discrete(normalize-weights(weights)))
    PBinomial(count, probability) ->
      ObsInt(sample-binomial(count, probability))
    PPoisson(rate) ->
      ObsInt(sample-poisson(rate))
    PGamma(shape, scale) ->
      ObsFloat64(sample-gamma(shape, scale))
    PBeta(alpha, beta) ->
      val x = sample-gamma(alpha, 1.0)
      val y = sample-gamma(beta, 1.0)
      ObsFloat64(x / (x + y))

pub fun log-prob(d : dist, value : observable) : <div> float64
  val finite-value = match value
    ObsFloat64(x) -> is-finite(x)
    _ -> True
  if not(is-valid(d)) || not(finite-value)
    then neginf
    else log-prob-valid(d.primitive, value)

fun log-prob-valid(primitive : primitive-dist, value : observable) : <div> float64
  match (primitive, value)
    (PNormal(mean, stddev), ObsFloat64(x)) ->
      val centered = (x - mean) / stddev
      (~0.5 * ln(2.0 * pi)) - ln(stddev) - (0.5 * centered * centered)
    (PUniform(low, high), ObsFloat64(x)) ->
      if x < low || x > high then neginf else ~(ln(high - low))
    (PBernoulli(p), ObsBool(x)) ->
      if x then ln(p) else ln(1.0 - p)
    (PDiscrete(weights), ObsInt(ix)) ->
      if ix < 0
        then neginf
        else
          match nth-prob(ix, normalize-weights(weights))
            Just(p) -> ln(p)
            Nothing -> neginf
    (PBinomial(count, p), ObsInt(k)) ->
      if k < 0 || k > count
        then neginf
        elif p == 0.0
          then if k == 0 then 0.0 else neginf
        elif p == 1.0
          then if k == count then 0.0 else neginf
        else log-choose(count, k) + (float64(k) * ln(p)) + (float64(count - k) * ln(1.0 - p))
    (PPoisson(rate), ObsInt(k)) ->
      if k < 0
        then neginf
        elif rate == 0.0
          then if k == 0 then 0.0 else neginf
        else (float64(k) * ln(rate)) - rate - log-factorial(k)
    (PGamma(shape, scale), ObsFloat64(x)) ->
      if x < 0.0
        then neginf
        elif x == 0.0
          then if shape < 1.0 then posinf elif shape == 1.0 then ~ln(scale) else neginf
        else ((shape - 1.0) * ln(x)) - (x / scale) - log-gamma(shape) - (shape * ln(scale))
    (PBeta(alpha, beta), ObsFloat64(x)) ->
      if x < 0.0 || x > 1.0
        then neginf
        elif x == 0.0
          then if alpha < 1.0 then posinf elif alpha == 1.0 then ln(beta) else neginf
        elif x == 1.0
          then if beta < 1.0 then posinf elif beta == 1.0 then ln(alpha) else neginf
        else ((alpha - 1.0) * ln(x)) + ((beta - 1.0) * ln(1.0 - x)) - log-beta(alpha, beta)
    _ ->
      neginf

pub fun normal-dist(mean : float64, stddev : float64) : dist
  Dist("normal", "normal(" ++ mean.show ++ ", " ++ stddev.show ++ ")", DistFloat64, PNormal(mean, stddev))

pub fun uniform-dist(low : float64, high : float64) : dist
  Dist("uniform", "uniform(" ++ low.show ++ ", " ++ high.show ++ ")", DistFloat64, PUniform(low, high))

pub fun bernoulli-dist(probability : float64) : dist
  Dist("bernoulli", "bernoulli(" ++ probability.show ++ ")", DistBool, PBernoulli(probability))

pub fun discrete-dist(weights : list<float64>) : dist
  Dist("discrete", "discrete(" ++ weights.map(fn(x){ x.show }).join(", ") ++ ")", DistInt, PDiscrete(weights))

pub fun binomial-dist(count : int, probability : float64) : dist
  Dist("binomial", "binomial(" ++ count.show ++ ", " ++ probability.show ++ ")", DistInt, PBinomial(count, probability))

pub fun poisson-dist(rate : float64) : dist
  Dist("poisson", "poisson(" ++ rate.show ++ ")", DistInt, PPoisson(rate))

pub fun gamma-dist(shape : float64, scale : float64) : dist
  Dist("gamma", "gamma(" ++ shape.show ++ ", " ++ scale.show ++ ")", DistFloat64, PGamma(shape, scale))

pub fun beta-dist(alpha : float64, beta : float64) : dist
  Dist("beta", "beta(" ++ alpha.show ++ ", " ++ beta.show ++ ")", DistFloat64, PBeta(alpha, beta))

fun normalize-weights(weights : list<float64>) : list<float64>
  // Scale before summing, so finite weights such as [1e308, 1e308] work.
  val largest = weights.foldl(0.0, fn(acc, x){ max(acc, x) })
  val scaled = weights.map(fn(x){ x / largest })
  val total = scaled.foldl(0.0, fn(acc, x){ acc + x })
  scaled.map(fn(x){ x / total })

fun nth-prob(index : int, weights : list<float64>) : maybe<float64>
  match weights
    Nil -> Nothing
    Cons(weight, rest) ->
      if index <= 0
        then Just(weight)
        else nth-prob(index - 1, rest)

fun sample-discrete(weights : list<float64>) : <random> int
  val threshold = random-float64()
  choose-weighted(threshold, weights, 0)

fun choose-weighted(threshold : float64, weights : list<float64>, index : int) : int
  match weights
    Nil -> max(0, index - 1)
    Cons(weight, rest) ->
      if threshold < weight
        then index
        else choose-weighted(threshold - weight, rest, index + 1)

fun sample-binomial(count : int, probability : float64) : <div,random> int
  if count <= 0
    then 0
    else
      val head = if random-float64() < probability then 1 else 0
      head + sample-binomial(count - 1, probability)

fun sample-poisson(rate : float64) : <div,random> int
  if rate == 0.0
    then 0
    elif rate > 32.0
      // Independent Poisson counts add. Bounded chunks avoid exp(-rate)
      // underflow, which otherwise truncates large-rate samples near 745.
      then sample-poisson(32.0) + sample-poisson(rate - 32.0)
    else
      val limit = exp(~rate)
      sample-poisson-loop(limit, 1.0, 0)

fun sample-poisson-loop(limit : float64, product : float64, count : int) : <div,random> int
  if product <= limit
    then count - 1
    else sample-poisson-loop(limit, product * random-float64(), count + 1)

fun sample-gamma(alpha : float64, theta : float64) : <div,random> float64
  if alpha < 1.0
    then
      val x = sample-gamma(alpha + 1.0, theta)
      x * exp(ln(random-float64()) / alpha)
    else
      val d = alpha - (1.0 / 3.0)
      val c = 1.0 / sqrt(9.0 * d)
      theta * sample-gamma-loop(d, c)

fun sample-gamma-loop(d : float64, c : float64) : <div,random> float64
  val z = standard-normal()
  val base = 1.0 + (c * z)
  if base <= 0.0
    then sample-gamma-loop(d, c)
    else
      val v = base * base * base
      val u = random-float64()
      if u < 1.0 - (0.0331 * z * z * z * z)
        then d * v
        elif ln(u) < (0.5 * z * z) + d * (1.0 - v + ln(v))
          then d * v
          else sample-gamma-loop(d, c)

fun standard-normal() : <random> float64
  val u1 = 1.0 - random-float64()
  val u2 = random-float64()
  sqrt(~2.0 * ln(u1)) * cos(2.0 * pi * u2)

fun log-factorial(n : int) : <div> float64
  log-gamma(float64(n + 1))

fun log-choose(n : int, k : int) : <div> float64
  log-factorial(n) - log-factorial(k) - log-factorial(n - k)

fun log-beta(alpha : float64, beta : float64) : <div> float64
  log-gamma(alpha) + log-gamma(beta) - log-gamma(alpha + beta)

fun log-gamma(x : float64) : <div> float64
  if x < 0.5
    then ln(pi) - ln(sin(pi * x)) - log-gamma(1.0 - x)
    else
      val coeffs =
        [0.99999999999980993,
         676.5203681218851,
         ~1259.1392167224028,
         771.32342877765313,
         ~176.61502916214059,
         12.507343278686905,
         ~0.13857109526572012,
         0.000009984369578019572,
         0.00000015056327351493116]
      val z = x - 1.0
      val t = z + 7.5
      val acc = lanczos-sum(coeffs, z, 0)
      0.5 * ln(2.0 * pi) + ((z + 0.5) * ln(t)) - t + ln(acc)

fun lanczos-sum(coeffs : list<float64>, z : float64, index : int) : float64
  match coeffs
    Nil -> 0.0
    Cons(x, rest) ->
      if index == 0
        then x + lanczos-sum(rest, z, index + 1)
        else (x / (z + float64(index))) + lanczos-sum(rest, z, index + 1)
