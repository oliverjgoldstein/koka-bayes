#!/bin/sh
set -e

source ~/.bash_profile

echo $KOKA_GIT

cd $KOKA_INSTALL

cd ./test/koka-bayes
rm *.kk
rm -r output/
mkdir output/
cp $KOKA_GIT/*.kk ./
cp -r $KOKA_GIT/output ./output

cd $KOKA_INSTALL

out/debug/koka-0.9.0-dev -c  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore
