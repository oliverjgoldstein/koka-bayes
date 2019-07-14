cd ./output/
python ./plot_examples.py
printf "Output written to: %s/output.html\n" "$(pwd)"

case "$OSTYPE" in
  darwin*)  open     output.html ;; 
  *)        xdg-open output.html ;;
esac

