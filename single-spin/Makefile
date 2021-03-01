all: spin

spin: spin.h spin.cpp main.cpp
	g++ \
		main.cpp \
		spin.h spin.cpp \
		-o spin

result.txt: spin
	./spin > result.txt

clean:
	rm -rf result.txt spin

.PHONY: clean result.txt