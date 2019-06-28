public module test/ojg/debug

fun loop(i : int, pop_hist : list<(int) -> int>) {
    if (i < 5) then {
      loop(i + 1, pop_hist)
    } else {
      pop_hist
    }
}


fun populate() {
  list(1, 5000) fun(i) {
    val t = fun(g : int) {g * 100 + g * 100}
    t
  }
}

fun show(lst : list<(int) -> int>) : string {
  var total_string := ""
  for(1, lst.length) fun(i) {
    val str = match(lst[i]) {
      Nothing -> ""
      Just(f) -> show(f(4))
    }
    total_string := total_string + str + "\n"
  }
  total_string
}


fun main() {
  val hist_list = populate()
  loop(0, hist_list)
}
