run-climate-experiments:
    koka -O2 --showelapsed climate-experiments.kk

remove-data:
    chmod +x ./bin/remove-data.sh
	./bin/remove-data.sh
