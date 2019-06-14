# export KOKAFILE=/Users/Development/Documents/Dissertation/koka/test/ojg/test.kk
# export KOKADIR=/Users/Development/Documents/Dissertation/koka

source ~/.bash_profile
cp koka-bayes.kk $KOKAFILE
cp exp.kk $KOKAFILE
cp bayes-handlers.kk $KOKAFILE
cd $KOKADIR
jake
