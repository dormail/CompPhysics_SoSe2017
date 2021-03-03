all: plot.pdf

pdf:
	mkdir -p pdf

ising: ising.cpp ising.h main.cpp
	g++ main.cpp ising.cpp -o ising

initial_phase: ising.cpp ising.h initial_phase.cpp
	g++ ising.cpp initial_phase.cpp -o initial_phase

plot.pdf: plot.py ising initial_phase pdf
	python3 plot.py

clear:
	rm -rf ising *.dat *.pdf