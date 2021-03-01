all: ising

ising: ising.h ising.cpp main.cpp
	g++ \
		main.cpp \
		ising.h ising.cpp \
		-o ising

result.txt: ising
	./ising > result.txt

clean:
	rm -rf result.txt ising

.PHONY: clean result.txt