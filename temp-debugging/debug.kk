import std/num/double
import std/os/path
import std/os/file

fun main() {
  pre_process_data()
}

fun pre_process_data() {
  val nums = replicate(5.0, 4000)
  println(nums.length)
  /* string_to_list_doubles(values) */
}

/* fun string_to_list_doubles( s : string )  {
  val nums = map(split(s, "\n"), parse-double)
  println(nums.length)
  match(nums[50]) {
    Nothing -> " "
    Just(x) -> match(x) {
      Nothing -> " "
      Just(v) -> show-fixed(v)
    }
  }
} */
