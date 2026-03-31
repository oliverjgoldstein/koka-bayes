public module exn-get

fun exn-get(xs : list<_a>, index : int) : exn _a {
  match(xs[index]) {
    Nothing -> throw("ListIndexError: Invalid list indexing at index: " ++ show(index))
    Just(x) -> x
  }
}

fun non_empty(l : list<a>) : bool {
  match(l) {
    Nil -> False
    Cons(_,_) -> True
  }
}
