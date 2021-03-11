all: plot.pdf runge-kutta

diffeq: main.cpp diffeq.cpp diffeq.h
	g++ main.cpp diffeq.cpp -o diffeq

runge-kutta: runge-kutta.cpp diffeq.h
	g++ runge-kutta.cpp -o runge-kutta

res.txt: diffeq
	./diffeq > res.txt

plot.pdf: plot.py res.txt
	python3 plot.py
