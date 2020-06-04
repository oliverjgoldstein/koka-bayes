This library has been tested on OSX Catalina, GHCI version 7.10.3, and Koka (commit c348fa7 : March 28th 2019)
This library uses shell scripts and thus requires unix/linux.

This is a probabilistic programming library that uses algebraic effects. It is based on Ohad Kammar's Eff Bayes.

This library has three working inference methods.
1. <b> Importance Sampling </b>
2. <b> Sequential Monte Carlo </b>
3. <b> Trace Markov Chain Monte Carlo </b>

The library also contains Particle Marginal Metropolis Hastings, but it does not currently work as expected.

Please see main.kk for a short demonstration of all three inference algorithms.

To install and run this library:

<b>To install koka-bayes:</b> <br />
From the root directory of where you download koka-bayes:
1. <code> make install </code>
2. <code> make dev </code> - this compiles the code.
2. <code> make analyze </code> - this runs the data analysis.

<b>Alternative commands:</b> <br />
From the root directory of where you download koka-bayes:
1. <code> make run </code> - this compiles and runs the code - not recommended unless you have many hours of compute time!
2. <code> make clean </code> - this cleans the compiled koka files.
3. <code> make clean-data </code> - this removes all the data and png files - not recommended unless you have reason to do so.
4. <code> make interactive </code> - this launches an interactive script with the library loaded.

The koka (kk) files at the root of the directory correspond to the implementation of the library.
The output files contain the output of inference and post-processing files for the markov chain and climate model.
The bin directory contains the make files.
The data directory contains pre-processing files and the data for the climate model.
