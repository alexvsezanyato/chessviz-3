all: chessviz

chessviz: build/Main.o build/Board.o
	g++ -Wall -Werror -o bin/chessviz \
	build/Main.o build/Board.o

build/Main.o: src/Main.cpp
	g++ -c -Wall -Werror -o build/Main.o \
	src/Main.cpp

build/Board.o: src/Board.cpp
	g++ -c -Wall -Werror -o build/Board.o \
	src/Board.cpp

install:
	sudo install ./bin/chessviz /usr/local/bin

uninstall:
	sudo rm -rf /usr/local/bin/chessviz

.PHONY: all