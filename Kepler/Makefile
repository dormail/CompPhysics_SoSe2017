all: dir_a/plot1.pdf

# test: kepler.cpp kepler.h
# 	g++ kepler.cpp -o test
#
# kepler-test.txt: test
# 	./test > kepler-test.txt
#
# plot: kepler-test.txt plot-test.py
# 	python3 plot-test.py

dir_a:
	mkdir -p dir_a

assignment_a: assignment_a.cpp kepler.h kepler.cpp dir_a
	g++ assignment_a.cpp  kepler.cpp -o assignment_a

dir_a/plot1.pdf: assignment_a plot_assignment_a.py
	./assignment_a
	python3 plot_assignment_a.py

clean:
	rm -rf kepler test *.txt *.pdf

.PHONY: clean
