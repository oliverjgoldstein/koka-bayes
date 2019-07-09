#!/bin/bash
set -e

LOCALS=$(pwd)/bin/local-vars.sh 
if [ ! -f "$LOCALS" ]; then
    echo "Error. Missing local-vars.sh!"
    exit 2
fi

chmod +x ./bin/local-vars.sh
source ./bin/local-vars.sh 

if [ ! -n "$KOKA_INSTALL" ]; then
  echo "Error. No install directory found!"
  exit 2
fi


if [ ! -n "$KOKA_GIT" ]; then
  echo "\n\n"
  echo "First parameter supplied!"
  echo "Please enter the ${green}DEVELOPMENT directory of the koka library!${reset}\n"
  echo "This should have the form:\n"
  echo "/dir1/dir2/../koka-bayes-master-development-etc\n"
  echo "This is needed in case you run this makefile from outside the github directory!\n"
  read koka_git
  echo "export KOKA_GIT=\"$koka_git\""$'\n' >>$LOCALS
  echo "Koka install directory added to local-vars.sh!"
fi

source ./bin/local-vars.sh 
cd $KOKA_INSTALL

cd ./test/koka-bayes
rm *.kk
rm -r output/
rm -r data/
mkdir output
mkdir data
cp $KOKA_GIT/*.kk ./
cp -r $KOKA_GIT/output/ .
cp -r $KOKA_GIT/data/ .

cd $KOKA_INSTALL

out/debug/koka-0.9.0-dev -c  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore
