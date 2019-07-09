#!/bin/bash
set -e
printf "\n\n"

LOCALS=$(pwd)/bin/local-vars.sh 
if [ ! -f "$LOCALS" ]; then
    printf "Error. Missing local-vars.sh!"
    exit 2
fi

chmod +x ./bin/local-vars.sh
source ./bin/local-vars.sh 

if [ ! -n "$KOKA_INSTALL" ]; then
  printf "Error. No install directory found!"
  exit 2
fi

cd $KOKA_INSTALL

out/debug/koka-0.9.0-dev -e  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore

cd ./test/koka-bayes/output/
python ./plot_examples.py
printf "\n\n"
printf "Output written to: %s/output.html\n" "$(pwd)"

