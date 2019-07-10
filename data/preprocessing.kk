public module data/preprocessing

import std/num/double
import std/os/path
import std/os/file
import exn-get
import effects-and-types

fun pre_process_data() : _e (list<list<row_vector>>, list<list<row_vector>>) {
  val uncertainties1 = map(split(read-text(path("./data/measurement-uncertainties1.txt")), "\n"), parse-double)
  val uncertainties2 = map(split(read-text(path("./data/measurement-uncertainties2.txt")), "\n"), parse-double)
  val temperatures1  = map(split(read-text(path("./data/temperature-readings1.txt")), "\n"), parse-double)
  val temperatures2  = map(split(read-text(path("./data/temperature-readings2.txt")), "\n"), parse-double)

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

/* fun get_from_every_thunk(index : int) {
  return fun(list : list<list<a>>) : exn list<a> {
    return exn-get(list, index)
  }
}

fun transpose(list : list<list<list<a>>>, index : int) : <div, exn> list<list<list<a>>> {
  if(index < 0) {
    [[Nil]]
  } else {
    [map(list, get_from_every_thunk(index))] + transpose(list, index - 1)
  }
} */

fun remove_maybes(list : list<maybe<double>>, return_list : list<double>) : exn list<double> {
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
fun list_of_lists(list : list<double>, length : int) : div list<list<double>> {
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

fun length_months( months : list<list<double>> ) : list<int> {
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
fun months( months : list<list<double>> ) : exn list<list<double>> {
  assert("Month lengths must be equal!", all_elements_equal(length_months(months)))
  var list_of_months : list<list<double>> := [Nil]
  for(0, 11) fun(i) {
    list_of_months := list_of_months + [by_month(months, i)]
  }
  list_of_months := tail(list_of_months)
  list_of_months
}

fun by_month( months : list<list<double>>, index : int ) : exn list<double> {
  remove_maybes(map(months, get_thunk(index)), Nil)
}

fun get_thunk( index : int ) {
  val x = fun( list : list<double> ) {
    list[index]
  }
  x
}

fun convert_to_groups( months : list<list<double>>, group_size : int ) : div list<list<list<double>>> {
  map(months, list_of_lists_thunk(group_size))
}

fun list_of_lists_thunk( length : int ) {
  return fun(list) {
    list_of_lists(list, length)
  }
}