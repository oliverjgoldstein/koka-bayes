This library has been tested on OSX Catalina, GHCI version 7.10.3, and Koka (commit c348fa7 : March 28th 2019).
This library uses shell scripts and thus requires unix/linux.

This is a probabilistic programming library that uses algebraic effects. It is based on the modular design of Ohad Kammar's <a href = "https://github.com/ohad/eff-bayes">Eff Bayes</a>.

This library has three working inference methods.
1. <b> Importance Sampling </b>
2. <b> Sequential Monte Carlo </b>
3. <b> Trace Markov Chain Monte Carlo </b>

The library also contains Particle Marginal Metropolis Hastings, but it does not currently work as expected.

Please see <b>main.kk</b> for a short demonstration of all three inference algorithms.

To install and run this library:

<b>To install koka-bayes:</b> <br />
From the root directory of where you download koka-bayes:
1. <code> make install </code>
2. <code> make clean </code> - this cleans the compiled koka files - this is fine to do.
3. <code> make dev </code> - this compiles the code.
4. <code> make run </code> - this compiles and runs the main.kk file.

<b>Alternative commands implemented</b> <br />
From the root directory of where you download koka-bayes:
1. <code> make clean-data </code> - this removes all the data (csv files and png images) from running the climate-experiments.kk file - not recommended unless you have reason to do so.
2. <code> make analyze </code> - this runs the data analysis.
3. <code> make interactive </code> - this launches an interactive script with the library loaded.

The koka (kk) files at the root of the directory correspond to the implementation of the library.
The <b>output</b> directory contains the output of inference and post-processing files for the markov chain and climate model (the climate model is contained in climate-experiments.kk).
The <b>bin</b> directory contains the make files.
The <b>data</b> directory contains pre-processing files and the data for the climate model.
