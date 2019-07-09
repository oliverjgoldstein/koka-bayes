#!/bin/bash
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

LOCALS=$(pwd)/bin/local-vars.sh 
if [ ! -f "$LOCALS" ]; then
    touch $LOCALS
fi

chmod +x ./bin/local-vars.sh
source ./bin/local-vars.sh 

if [ ! -n "$KOKA_INSTALL" ]; then
  echo "\n\n"
  echo "First parameter supplied!"
  echo "Please enter the ${green}install directory of koka!${reset}\n"
  echo "This should have the form:\n"
  echo "/dir1/dir2/../koka\n"
  read install_directory
  echo "export KOKA_INSTALL=\"$install_directory\""$'\n' >>$LOCALS
  echo "Koka install directory added to ./bin/local-vars.sh!"
fi

source ./bin/local-vars.sh 
echo "Install directory: "
echo $KOKA_INSTALL
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
cp -r $GIT_DIR/data ./data
cd ..
cd ..

if [ ! -d "./out/koka-bayes-output/" ]; then
  mkdir ./out/koka-bayes-output
fi

echo "${green}Successfully installed koka-bayes!${reset}"
