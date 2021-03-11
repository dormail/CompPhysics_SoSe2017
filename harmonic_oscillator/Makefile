all: plot.pdf runge-kutta

diffeq: main.cpp diffeq.cpp diffeq.h
	g++ main.cpp diffeq.cpp -o diffeq

runge-kutta: runge-kutta.cpp diffeq.h
	g++ runge-kutta.cpp -o runge-kutta

res.txt: diffeq
	./diffeq > res.txt

runge-kutta2.txt: runge-kutta
	./runge-kutta > runge-kutta2.txt

plot.pdf: plot.py res.txt runge-kutta2.txt
	python3 plot.py

clean:
	rm -rf *.pdf runge-kutta2 runge-kutta diffeq *.txt
