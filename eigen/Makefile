all: result.txt

diagonalization: main.cpp diagonalization.h householder.cpp jacobi_rotation.cpp
	g++ main.cpp \
	householder.cpp \
	jacobi_rotation.cpp \
	-o diagonalization

result.txt: diagonalization
	rm -rf result.txt
	./diagonalization | tee result.txt

make clean:
	rm -rf *.txt diagonalization