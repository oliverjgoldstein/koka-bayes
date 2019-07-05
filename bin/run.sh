#!/bin/sh
set -e
echo "\n\n"
source ~/.bash_profile

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

out/debug/koka-0.9.0-dev -e  --outdir=out/koka-bayes-output/ -ilib test/koka-bayes/main -itest/lib --core --checkcore

cd ./test/koka-bayes/output/
python ./plot_examples.py
echo "\n\n"
open output.html
