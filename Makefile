target: dev

install:
	chmod +x ./bin/install-koka-bayes.sh
	chmod +x ./bin/run.sh
	chmod +x ./bin/dev.sh
	chmod +x ./bin/interactive.sh
	chmod +x ./bin/clean.sh
	chmod +x ./bin/clean-data.sh
	chmod +x ./bin/run-analysis.sh
	./bin/install-koka-bayes.sh

run:
	./bin/run.sh
	
dev:
	./bin/dev.sh
	
interactive:
	./bin/interactive.sh
	
clean:
		./bin/clean.sh
		
clean-data:
		./bin/clean-data.sh
		
analyze:
		./bin/run-analysis.sh