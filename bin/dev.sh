#!/bin/sh
set -e

source ~/.bash_profile

if [ ! -n "$KOKA_GIT" ]; then
  echo "\n\n"
  echo "First parameter supplied!"
  echo "Please enter the ${green}DEVELOPMENT directory of the koka library!${reset}\n"
  echo "This should have the form:\n"
  echo "\dir1\dir2\..\koka-bayes-master\n"
  echo "This is needed in case you run this makefile from outside the github directory!"
  read koka_git
  echo "export KOKA_INSTALL=\"$koka_git\"" >>~/.bash_profile
  echo "Koka install directory added to bash_profile!"
fi

if [ ! -n "$KOKA_INSTALL" ]; then
  echo "\n\n"
  echo "First parameter supplied!"
  echo "Please enter the ${green}install directory of koka!${reset}\n"
  echo "This should have the form:\n"
  echo "\dir1\dir2\..\koka\n"
  read install_directory
  echo "export KOKA_INSTALL=\"$install_directory\"" >>~/.bash_profile
  echo "Koka install directory added to bash_profile!"
fi

cd $KOKA_INSTALL

cd ./test/koka-bayes
rm *.kk
rm -r output/
mkdir output
cp $KOKA_GIT/*.kk ./
cp -r $KOKA_GIT/output/ ./output

cd $KOKA_INSTALL

out/debug/koka-0.9.0-dev -c  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore
