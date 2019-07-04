
source ~/.bash_profile
if [ ! -n "$KOKA_INSTALL" ]; then
  echo "First parameter supplied!"
  echo "Please enter the install directory of koka!\n"
  echo "This should have the form:\n"
  echo "\absolute-directory\..\..\koka\n"
  read install_directory
  echo "export KOKA_INSTALL=\"$install_directory\"" >>~/.bash_profile
  echo "Koka install directory added to bash_profile!"
fi

cd $KOKA_INSTALL

if [ -d "./test/ojg/" ]; then
  echo "Your existing version of koka-bayes will be overwritten!"
  read -p "Continue (y/n)?" choice
  case "$choice" in
    y|Y ) echo "yes";;
    n|N ) exit 0;;
    * ) echo "Invalid - re run install to try again"; exit 0;;
  esac
  rm -r ./test/ojg/
fi

mkdir ./test/ojg/
cd ./test/ojg
touch whatever.txt
