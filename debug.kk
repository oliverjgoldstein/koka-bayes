import std/num/ddouble
import std/os/path
import std/os/file

fun main() {
  pre_process_data()
}

fun pre_process_data() {
  val nums = replicate(5.0, 4000)
  println(nums.length)
  /* string_to_list_ddoubles(values) */
}

/* fun string_to_list_ddoubles( s : string )  {
  val nums = map(split(s, "\n"), parse-ddouble)
  println(nums.length)
  match(nums[50]) {
    Nothing -> " "
    Just(x) -> match(x) {
      Nothing -> " "
      Just(v) -> show-fixed(v)
    }
  }
} */
