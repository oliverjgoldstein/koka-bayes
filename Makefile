target: dev

install:
	chmod +x ./bin/install-koka-bayes.sh
	chmod +x ./bin/run.sh
	chmod +x ./bin/dev.sh
	chmod +x ./bin/interactive.sh
	chmod +x ./bin/clean.sh
	./bin/install-koka-bayes.sh

run:
	./bin/run.sh
	
dev:
	./bin/dev.sh
	
interactive:
	./bin/interactive.sh
	
clean:
		./bin/clean.sh