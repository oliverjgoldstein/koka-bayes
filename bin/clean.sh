#!/bin/bash

rm ./output/gaussian/*.png
rm ./output/gaussian/*.csv
rm ./output/months/jan/*.csv
rm ./output/months/feb/*.csv
rm ./output/months/mar/*.csv
rm ./output/months/apr/*.csv
rm ./output/months/may/*.csv
rm ./output/months/jun/*.csv
rm ./output/months/jul/*.csv
rm ./output/months/aug/*.csv
rm ./output/months/sep/*.csv
rm ./output/months/oct/*.csv
rm ./output/months/nov/*.csv
rm ./output/months/dec/*.csv

rm ./output/months/jan/*.png
rm ./output/months/feb/*.png
rm ./output/months/mar/*.png
rm ./output/months/apr/*.png
rm ./output/months/may/*.png
rm ./output/months/jun/*.png
rm ./output/months/jul/*.png
rm ./output/months/aug/*.png
rm ./output/months/sep/*.png
rm ./output/months/oct/*.png
rm ./output/months/nov/*.png
rm ./output/months/dec/*.png


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

printf "Cleaned"

printf "\n\n"