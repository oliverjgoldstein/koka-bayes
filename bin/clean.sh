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
cd ./out/
rm -r ./koka-bayes-output/
mkdir ./koka-bayes-output/