fun plot_population_regression(histogram : histogram<(double -> double)>, default : (exp, (double -> double))) : <ndet, console, sample> string {
  val negligible = length(filter(histogram,
    fun(element){
      match(element) {
          (Exp(j),_) -> (dbl-e^(j) < 0.00001)
      }
    }))
    println("Number of negligible samples: " + negligible.show)
    list-join(15) fun(i) {
      val f = weighted_choice(histogram, default)
      plot(f)
    }
}
