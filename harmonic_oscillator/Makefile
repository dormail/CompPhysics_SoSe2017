all: plot.pdf

diffeq: main.cpp diffeq.cpp diffeq.h
	g++ main.cpp diffeq.cpp -o diffeq

res.txt: diffeq
	./diffeq > res.txt

plot.pdf: plot.py res.txt
	python3 plot.py
