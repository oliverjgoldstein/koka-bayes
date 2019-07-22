import std/num/double
import model-resources
/* import effects-and-types */

ambient fun sample() : double

fun gamrand(alpha : double) {
  if(alpha>1.0) {

    var flag := True
    while {flag} {
      flag := True
    }
    
    0.0
  }
  else {
    val x = gamrand(alpha);
    return sample()
  }
}
