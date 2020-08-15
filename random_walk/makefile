clear:
	rm -rf random_walk.o random_walk_test.o

build: main.cpp random_walk.cpp functions.h random_walk_distance.cpp take_average.cpp help.cpp
	g++ \
		take_average.cpp \
		main.cpp \
		random_walk.cpp \
		random_walk_distance.cpp \
		help.cpp \
		-o random_walk.o \
		-lpthread

test: random_walk_test.cpp random_walk.cpp functions.h random_walk_distance.cpp take_average.cpp
	clear
	g++ \
		take_average.cpp \
		random_walk_test.cpp \
		random_walk.cpp \
		random_walk_distance.cpp \
		-o random_walk_test.o
