module autodiff/model

import std/num/float64
import autodiff/smooth
import core/model
import core/env
import core/obsvar
import core/obsvalue

// A small continuous model interface. Coordinates are the latent Normal sites
// in execution order; named observed sites consume the supplied data in order.
pub effect continuous<a>
  fun normal-latent(mean : a, stddev : a) : a
  fun normal-observed(name : string, mean : a, stddev : a) : a

// The same source model can use the existing probabilistic handlers.
pub fun probabilistic(action : () -> <continuous<float64>,smooth<float64>|e> r) : model<e,r>
  fn(){
    mask<obs-reader>{
      mask<div>{
        evaluate(fn(){
          handle(fn(){ mask<model-dist>{ action() } })
            return(result) result
            fun normal-latent(mean, stddev) normal'(mean, stddev)
            fun normal-observed(name, mean, stddev) normal(obs-float64(name), mean, stddev)
        })
      }
    }
  }

// Interpret model operations first, leaving only smooth arithmetic for AD.
// Observations must be present and the coordinate count must match exactly.
// A mismatch yields -infinity, which gradient samplers reject (or reject as
// an invalid initialization). This does not differentiate random sampling.
pub fun log-joint(action : () -> <continuous<a>,smooth<a>> r,
                  coordinates : list<a>, observations : env) : smooth<a> a
  var remaining := coordinates
  var data := observations
  var valid := True
  var score := ad-constant(0.0)
  val model-result = handle(action)
    return(result) result
    fun normal-latent(mean, stddev)
      val value = match remaining
        Cons(x, rest) ->
          remaining := rest
          x
        Nil ->
          valid := False
          ad-constant(0.0)
      score := ad-add(score, ad-normal-log-density(value, mean, stddev))
      value
    fun normal-observed(name, mean, stddev)
      val (found, rest) = maybe-consume-name(name, data)
      data := rest
      val value = match found
        Just(ObsFloat64(x)) -> ad-constant(x)
        _ ->
          valid := False
          ad-constant(0.0)
      score := ad-add(score, ad-normal-log-density(value, mean, stddev))
      value
  if valid && remaining.is-empty then score else ad-constant(neginf)
