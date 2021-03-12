all: plot

test: kepler.cpp kepler.h
	g++ kepler.cpp -o test

kepler-test.txt: test
	./test > kepler-test.txt

plot: kepler-test.txt plot-test.py
	python3 plot-test.py

clean:
	rm -rf kepler test *.txt *.pdf

.PHONY: clean
