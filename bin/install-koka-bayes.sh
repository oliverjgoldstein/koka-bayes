#!/bin/sh
set -e

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

echo "\n"
echo "This make script ${red}MUST${reset} be run from the root directory of the koka-bayes install location!"
echo "\n"

read -p "Is this run from the root of ${green}koka-bayes${reset} (y/n)? " choice
case "$choice" in
  y|Y ) echo "${green}Proceeding${reset}";;
  n|N ) exit 0;;
  * ) echo "Invalid - re run install to try again"; exit 0;;
esac

GIT_DIR=$(pwd)

source ~/.bash_profile
if [ ! -n "$KOKA_INSTALL" ]; then
  echo "\n\n"
  echo "First parameter supplied!"
  echo "Please enter the ${green}install directory of koka!${reset}\n"
  echo "This should have the form:\n"
  echo "\absolute-directory\..\..\koka\n"
  read install_directory
  echo "export KOKA_INSTALL=\"$install_directory\"" >>~/.bash_profile
  echo "Koka install directory added to bash_profile!"
fi

cd $KOKA_INSTALL

if [ -d "./test/koka-bayes/" ]; then
  echo "\n\n"
  echo "Your existing version of koka-bayes will be ${red}overwritten!${reset}"
  read -p "Continue (y/n)? " choice
  case "$choice" in
    y|Y ) echo "${green}Proceeding${reset}";;
    n|N ) exit 0;;
    * ) echo "Invalid - re run install to try again"; exit 0;;
  esac
  rm -r ./test/koka-bayes/
fi

echo "\n\n"

mkdir ./test/koka-bayes/
cd ./test/koka-bayes
cp $GIT_DIR/*.kk ./
cp -r $GIT_DIR/output ./output
cd ..
cd ..

if [ ! -d "./out/koka-bayes-output/" ]; then
  mkdir ./out/koka-bayes-output
fi

echo "${green}Successfully installed koka-bayes!${reset}"