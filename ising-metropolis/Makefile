all: plot.pdf

ising: ising.cpp ising.h main.cpp
	g++ main.cpp ising.cpp -o ising

plot.pdf: plot.py ising
	python3 plot.py

clear:
	rm -rf ising *.dat *.pdf