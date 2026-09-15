module core/model

import std/core/debug
import std/num/random
import core/dist
import core/obsvalue
import core/obsvar

pub alias model<e,a> = () -> <obs-reader,model-dist,div|e> a

pub effect obs-reader
  fun read-observation(name : string) : maybe<observable>

pub effect model-dist
  fun draw(dist : dist) : observable
  fun draw-observable(name : string, dist : dist) : observable

pub effect val sample-hook : ((maybe<string>, dist) -> <div,random> observable)
pub effect val observe-hook : ((string, dist, observable) -> <div,random> observable)

fun expect-float64(value : observable) : float64
  match value
    ObsFloat64(x) -> x
    _             -> impossible("expected a float64 observable")

fun expect-int(value : observable) : int
  match value
    ObsInt(x) -> x
    _         -> impossible("expected an int observable")

fun expect-bool(value : observable) : bool
  match value
    ObsBool(x) -> x
    _          -> impossible("expected a bool observable")

pub fun sample-only-float64(d : dist) : <model-dist|e> float64
  expect-float64(draw(d))

pub fun sample-only-int(d : dist) : <model-dist|e> int
  expect-int(draw(d))

pub fun sample-only-bool(d : dist) : <model-dist|e> bool
  expect-bool(draw(d))

pub fun normal(v : obsvar<float64>, mean : float64, stddev : float64) : <model-dist|e> float64
  expect-float64(draw-observable(v.name, normal-dist(mean, stddev)))

pub fun normal'(mean : float64, stddev : float64) : <model-dist|e> float64
  expect-float64(draw(normal-dist(mean, stddev)))

pub fun uniform(v : obsvar<float64>, low : float64, high : float64) : <model-dist|e> float64
  expect-float64(draw-observable(v.name, uniform-dist(low, high)))

pub fun uniform'(low : float64, high : float64) : <model-dist|e> float64
  expect-float64(draw(uniform-dist(low, high)))

pub fun bernoulli(v : obsvar<bool>, p : float64) : <model-dist|e> bool
  expect-bool(draw-observable(v.name, bernoulli-dist(p)))

pub fun bernoulli'(p : float64) : <model-dist|e> bool
  expect-bool(draw(bernoulli-dist(p)))

pub fun discrete(v : obsvar<int>, weights : list<float64>) : <model-dist|e> int
  expect-int(draw-observable(v.name, discrete-dist(weights)))

pub fun discrete'(weights : list<float64>) : <model-dist|e> int
  expect-int(draw(discrete-dist(weights)))

pub fun binomial(v : obsvar<int>, n : int, p : float64) : <model-dist|e> int
  expect-int(draw-observable(v.name, binomial-dist(n, p)))

pub fun binomial'(n : int, p : float64) : <model-dist|e> int
  expect-int(draw(binomial-dist(n, p)))

pub fun poisson(v : obsvar<int>, rate : float64) : <model-dist|e> int
  expect-int(draw-observable(v.name, poisson-dist(rate)))

pub fun poisson'(rate : float64) : <model-dist|e> int
  expect-int(draw(poisson-dist(rate)))

pub fun gamma(v : obsvar<float64>, shape : float64, scale : float64) : <model-dist|e> float64
  expect-float64(draw-observable(v.name, gamma-dist(shape, scale)))

pub fun gamma'(shape : float64, scale : float64) : <model-dist|e> float64
  expect-float64(draw(gamma-dist(shape, scale)))

pub fun beta(v : obsvar<float64>, alpha : float64, beta-value : float64) : <model-dist|e> float64
  expect-float64(draw-observable(v.name, beta-dist(alpha, beta-value)))

pub fun beta'(alpha : float64, beta-value : float64) : <model-dist|e> float64
  expect-float64(draw(beta-dist(alpha, beta-value)))
