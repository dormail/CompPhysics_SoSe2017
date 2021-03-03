all: pdf/merged.pdf

pdf:
	mkdir -p pdf

ising: ising.cpp ising.h main.cpp
	g++ main.cpp ising.cpp -o ising

initial_phase: ising.cpp ising.h initial_phase.cpp
	g++ ising.cpp initial_phase.cpp -o initial_phase

pdf/compare_initial*.pdf: plot.py ising initial_phase pdf
	python3 plot.py

pdf/merged.pdf: pdf/compare_initial*.pdf
	pdfunite pdf/compare_initial*.pdf pdf/merged.pdf

clean:
	rm -rf ising *.dat *pdf initial_phase

.PHONY: clean