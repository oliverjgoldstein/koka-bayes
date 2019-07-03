fun arb(arbitrary : list<_a>) {

  val i = ref(0)
  fun func(parameter) {
    i := inject-st({parameter(0)})()
    /* parameter(!i) */
  }

  val temp = ref(arbitrary.map(func))
  !i
}
