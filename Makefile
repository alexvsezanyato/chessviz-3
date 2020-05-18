all: chessviz

chessviz: build/Main.o build/Board.o build/PlainBoardPrinter.o build/Moves.o
	g++ -Wall -Werror -o bin/chessviz \
	build/Main.o \
	build/Board.o \
	build/PlainBoardPrinter.o \
	build/Moves.o

build/Main.o: src/Main.cpp
	g++ -c -Wall -Werror -o build/Main.o \
	src/Main.cpp

build/Board.o: src/Board.cpp
	g++ -c -Wall -Werror -o build/Board.o \
	src/Board.cpp

build/PlainBoardPrinter.o: src/PlainBoardPrinter.cpp
	g++ -c -Wall -Werror -o build/PlainBoardPrinter.o \
	src/PlainBoardPrinter.cpp

build/Moves.o: src/Moves.cpp
	g++ -c -Wall -Werror -o build/Moves.o \
    src/Moves.cpp

format:
	clang-format -i src/*.cpp src/*.h

install:
	sudo install ./bin/chessviz /usr/local/bin

uninstall:
	sudo rm -rf /usr/local/bin/chessviz

.PHONY: all install uninstall format