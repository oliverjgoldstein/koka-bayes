#!/bin/sh
set -e
echo "\n\n"

LOCALS=$(pwd)/bin/local-vars.sh 
if [[ ! -f "$LOCALS" ]]; then
    echo "Error. Missing local-vars.sh!"
    exit 2
fi

chmod +x ./bin/local-vars.sh
source ./bin/local-vars.sh 

if [ ! -n "$KOKA_INSTALL" ]; then
  echo "Error. No install directory found!"
  exit 2
fi

cd $KOKA_INSTALL

out/debug/koka-0.9.0-dev -e  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore

cd ./test/koka-bayes/output/
python ./plot_examples.py
echo "\n\n"
open output.html
