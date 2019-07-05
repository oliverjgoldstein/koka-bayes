#!/bin/sh
set -e
echo "\n\n"
source ~/.bash_profile
cd $KOKA_INSTALL

out/debug/koka-0.9.0-dev -e  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore

cd ./test/koka-bayes/output/
python ./plot_examples.py
echo "\n\n"
open output.html
