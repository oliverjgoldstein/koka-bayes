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

$KOKA_INSTALL/out/debug/koka-0.9.0-dev --outdir=$KOKA_INSTALL/out/koka-bayes-output/ -i"$KOKA_INSTALL/lib" -i"$KOKA_INSTALL/test/lib" $KOKA_GIT/main --core --checkcore
