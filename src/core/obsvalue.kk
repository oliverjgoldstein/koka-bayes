module core/obsvalue

import std/num/float64

pub type observable
  ObsFloat64(value : float64)
  ObsInt(value : int)
  ObsBool(value : bool)

pub struct codec<a>
  kind   : string
  encode : a -> observable
  decode : observable -> maybe<a>
  render : a -> string

pub fun encode-value(codec : codec<a>, value : a) : observable
  val f = codec.encode
  f(value)

pub fun decode-value(codec : codec<a>, value : observable) : maybe<a>
  val f = codec.decode
  f(value)

pub fun render-value(codec : codec<a>, value : a) : string
  val f = codec.render
  f(value)

pub fun float64-codec() : codec<float64>
  Codec("float64",
        fn(x) ObsFloat64(x),
        fn(v){
          match v
            ObsFloat64(x) -> Just(x)
            _             -> Nothing
        },
        fn(x) x.show)

pub fun int-codec() : codec<int>
  Codec("int",
        fn(x) ObsInt(x),
        fn(v){
          match v
            ObsInt(x) -> Just(x)
            _         -> Nothing
        },
        fn(x) x.show)

pub fun bool-codec() : codec<bool>
  Codec("bool",
        fn(x) ObsBool(x),
        fn(v){
          match v
            ObsBool(x) -> Just(x)
            _          -> Nothing
        },
        fn(x) if x then "true" else "false")

pub fun show-obsvalue(value : observable) : string
  match value
    ObsFloat64(x) -> x.show
    ObsInt(x)     -> x.show
    ObsBool(x)    -> if x then "true" else "false"
