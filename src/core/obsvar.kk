module core/obsvar

import core/obsvalue

pub struct obsvar<a>
  name  : string
  codec : codec<a>

pub fun obsvar(name : string, codec : codec<a>) : obsvar<a>
  Obsvar(name, codec)

pub fun obs-float64(name : string) : obsvar<float64>
  Obsvar(name, float64-codec())

pub fun obs-int(name : string) : obsvar<int>
  Obsvar(name, int-codec())

pub fun obs-bool(name : string) : obsvar<bool>
  Obsvar(name, bool-codec())

pub fun same(v1 : obsvar<a>, v2 : obsvar<b>) : bool
  v1.name == v2.name

pub fun show(v : obsvar<a>) : string
  v.name
