# export KOKARUN=/Users/Development/Documents/Dissertation/koka/test/ojg
# export KOKADEV=/Users/Development/Documents/Dissertation/koka

source ~/.bash_profile
cp KOKARUN/* KOKADEV/
jake
python plot_examples.py
