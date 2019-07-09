target: run

install:
	chmod +x ./bin/install-koka-bayes.sh
	chmod +x ./bin/run.sh
	chmod +x ./bin/dev.sh
	./bin/install-koka-bayes.sh

run:
	./bin/run.sh

dev:
	./bin/dev.sh
