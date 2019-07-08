public module test/koka-bayes/data/preprocessing

import std/num/ddouble
import std/os/path
import std/os/file
import test/koka-bayes/exn-get
import test/koka-bayes/effects-and-types

fun pre_process_data() : _e (list<list<row_vector>>, list<list<row_vector>>) {
  val uncertainties1 = map(split(read-text(path("./test/koka-bayes/data/measurement-uncertainties1.txt")), "\n"), parse-ddouble)
  val uncertainties2 = map(split(read-text(path("./test/koka-bayes/data/measurement-uncertainties2.txt")), "\n"), parse-ddouble)
  val temperatures1  = map(split(read-text(path("./test/koka-bayes/data/temperature-readings1.txt")), "\n"), parse-ddouble)
  val temperatures2  = map(split(read-text(path("./test/koka-bayes/data/temperature-readings2.txt")), "\n"), parse-ddouble)

  val maybe_uncertainties = concat([uncertainties1, uncertainties2])
  val maybe_temperatures  = concat([temperatures1, temperatures2])
  
  val uncertainties = remove_maybes(maybe_uncertainties, Nil)
  val temperatures = remove_maybes(maybe_temperatures, Nil)
  
  val uncertainties_by_year = list_of_lists(uncertainties, 12)
  val temperatures_by_year  = list_of_lists(temperatures, 12)
  
  val uncertainties_by_month = months(uncertainties_by_year)
  val temperatures_by_month = months(temperatures_by_year)
  
  val grouped_uncertainties_by_month = convert_to_groups(uncertainties_by_month, 20)
  val grouped_temperatures_by_month = convert_to_groups(temperatures_by_month, 20)
  
  (grouped_uncertainties_by_month, grouped_temperatures_by_month)
}

fun remove_maybes(list : list<maybe<ddouble>>, return_list : list<ddouble>) : exn list<ddouble> {
  match(list) {
    Nil -> return_list 
    Cons(x,y) -> {
      match(x) {
        Nothing -> error("Preprocessing error: There are nothings! Please check the input file!")
        Just(a) -> {
          val new_list = remove_maybes(y, return_list + [a])
          new_list
        }
      }
    }
  }
}

// Returns a list of lists where each list corresponds to a single year (if called with parameter 12).
// Preserves order.
fun list_of_lists(list : list<ddouble>, length : int) : div list<list<ddouble>> {
  if (length == 0) {
    return [list]
  } else {
  match(list) {
      Nil -> Nil
      Cons(_,_) -> {
        val list_split = split(list, length)
        return [list_split.fst] + list_of_lists(list_split.snd, length)
      }
    }
  }
}

fun length_months( months : list<list<ddouble>> ) : list<int> {
  match(months) {
    Nil -> Nil
    Cons(x,y) -> [length(x)] + length_months(y)
  }
}

fun all_elements_equal( list : list<int> ) : exn bool { 
  assert("List must be non_empty!", non_empty(list))
  val first_length = exn-get(list, 0)
  var bool_val := True
  for(0, list.length - 1) fun(i) {
    if (exn-get(list, i) != first_length) {
      bool_val := False
    }
  }
  return bool_val
} 

/* [[1,2,3,4,5,6,...12],[1,2,3,4,5,6...12]...] -> [[1,1,1,1,1,..........1,1,1,1],[2,2,2,2,2,2,......2,2,2,]] */
fun months( months : list<list<ddouble>> ) : exn list<list<ddouble>> {
  assert("Month lengths must be equal!", all_elements_equal(length_months(months)))
  var list_of_months : list<list<ddouble>> := [Nil]
  for(0, 11) fun(i) {
    list_of_months := list_of_months + [by_month(months, i)]
  }
  list_of_months := tail(list_of_months)
  list_of_months
}

fun by_month( months : list<list<ddouble>>, index : int ) : exn list<ddouble> {
  remove_maybes(map(months, get_thunk(index)), Nil)
}

fun get_thunk( index : int ) {
  val x = fun( list : list<ddouble> ) {
    list[index]
  }
  x
}

fun convert_to_groups( months : list<list<ddouble>>, group_size : int ) : div list<list<list<ddouble>>> {
  map(months, list_of_lists_thunk(group_size))
}

fun list_of_lists_thunk( length : int ) {
  return fun(list) {
    list_of_lists(list, length)
  }
}