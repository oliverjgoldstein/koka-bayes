type whatever<a> {
  Whatever(a : a)
}


fun arb(vale : whatever<_a>) : whatever<_a> {
  match(vale) {
    Whatever(a) -> {
      Whatever(a)
    }
  }
}

fun arb2(cool : whatever<a>) : div whatever<a>  {
  var main_val := cool
  for(1, 10) fun(i) {
    main_val := arb(main_val)
  }

  main_val
}
