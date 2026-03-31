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

pub fun sample(d : dist) : <div,random> observable
  match d.primitive
    PNormal(mean, stddev) ->
      ObsFloat64(mean + (stddev * standard-normal()))
    PUniform(low, high) ->
      val lo = min(low, high)
      val hi = max(low, high)
      ObsFloat64(lo + ((hi - lo) * random-float64()))
    PBernoulli(probability) ->
      ObsBool(random-float64() < clamp-prob(probability))
    PDiscrete(weights) ->
      ObsInt(sample-discrete(normalize-weights(weights)))
    PBinomial(count, probability) ->
      ObsInt(sample-binomial(count, clamp-prob(probability)))
    PPoisson(rate) ->
      val lam = if rate <= 0.0 then 1.0e-9 else rate
      ObsInt(sample-poisson(lam))
    PGamma(shape, scale) ->
      val alpha = if shape <= 0.0 then 1.0e-9 else shape
      val theta = if scale <= 0.0 then 1.0e-9 else scale
      ObsFloat64(sample-gamma(alpha, theta))
    PBeta(alpha, beta) ->
      val a = if alpha <= 0.0 then 1.0e-9 else alpha
      val b = if beta <= 0.0 then 1.0e-9 else beta
      val x = sample-gamma(a, 1.0)
      val y = sample-gamma(b, 1.0)
      ObsFloat64(x / (x + y))

pub fun log-prob(d : dist, value : observable) : <div> float64
  match (d.primitive, value)
    (PNormal(mean, stddev), ObsFloat64(x)) ->
      val variance = stddev * stddev
      val centered = x - mean
      (~0.5 * ln(2.0 * pi * variance)) - ((centered * centered) / (2.0 * variance))
    (PUniform(low, high), ObsFloat64(x)) ->
      val lo = min(low, high)
      val hi = max(low, high)
      if x < lo || x > hi || hi == lo then neginf else ~(ln(hi - lo))
    (PBernoulli(probability), ObsBool(x)) ->
      val p = clamp-prob(probability)
      if x then ln(p) else ln(1.0 - p)
    (PDiscrete(weights), ObsInt(ix)) ->
      match nth-prob(ix, normalize-weights(weights))
        Just(p) -> ln(p)
        Nothing -> neginf
    (PBinomial(count, probability), ObsInt(k)) ->
      val p = clamp-prob(probability)
      if k < 0 || k > count
        then neginf
        else log-choose(count, k) + (float64(k) * ln(p)) + (float64(count - k) * ln(1.0 - p))
    (PPoisson(rate), ObsInt(k)) ->
      val lam = if rate <= 0.0 then 1.0e-9 else rate
      if k < 0
        then neginf
        else (float64(k) * ln(lam)) - lam - log-factorial(k)
    (PGamma(shape, scale), ObsFloat64(x)) ->
      val alpha = if shape <= 0.0 then 1.0e-9 else shape
      val theta = if scale <= 0.0 then 1.0e-9 else scale
      if x <= 0.0
        then neginf
        else ((alpha - 1.0) * ln(x)) - (x / theta) - log-gamma(alpha) - (alpha * ln(theta))
    (PBeta(alpha, beta), ObsFloat64(x)) ->
      val a = if alpha <= 0.0 then 1.0e-9 else alpha
      val b = if beta <= 0.0 then 1.0e-9 else beta
      if x <= 0.0 || x >= 1.0
        then neginf
        else ((a - 1.0) * ln(x)) + ((b - 1.0) * ln(1.0 - x)) - log-beta(a, b)
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

fun clamp-prob(p : float64) : float64
  if p <= 1.0e-9 then 1.0e-9
  elif p >= 1.0 - 1.0e-9 then 1.0 - 1.0e-9
  else p

fun normalize-weights(weights : list<float64>) : list<float64>
  val total = weights.foldl(0.0, fn(acc, x){ acc + x })
  if total <= 0.0
    then weights.map(fn(_x){ 1.0 / float64(weights.length) })
    else weights.map(fn(x){ x / total })

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
      if threshold <= weight
        then index
        else choose-weighted(threshold - weight, rest, index + 1)

fun sample-binomial(count : int, probability : float64) : <div,random> int
  if count <= 0
    then 0
    else
      val head = if random-float64() < probability then 1 else 0
      head + sample-binomial(count - 1, probability)

fun sample-poisson(rate : float64) : <div,random> int
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
  val u1 = max(1.0e-12, random-float64())
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
