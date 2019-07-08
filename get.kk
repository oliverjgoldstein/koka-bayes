public module test/koka-bayes/get

fun get(xs : list<_a>, index : int) : exn _a {
  match(xs[index]) {
    Nothing -> error("ListIndexError: Invalid list indexing at index: " + show(index))
    Just(x) -> x
  }
}

fun non_empty(l : list<a>) : bool {
  match(l) {
    Nil -> False
    Cons(_,_) -> True
  }
}
