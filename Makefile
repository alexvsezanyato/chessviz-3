# app

appName := chessviz

objects := build/Main.o
objects += build/Board.o
objects += build/PlainBoardPrinter.o
objects += build/Moves.o

all: bin/${appName}

bin/${appName}: ${objects}
	@g++ -Wall -Werror -o bin/${appName} ${objects}

build/Main.o: src/Main.cpp
	@g++ -c -Wall -Werror -o build/Main.o \
	src/Main.cpp

build/Board.o: src/Board.cpp
	@g++ -c -Wall -Werror -o build/Board.o \
	src/Board.cpp

build/PlainBoardPrinter.o: src/PlainBoardPrinter.cpp
	@g++ -c -Wall -Werror -o build/PlainBoardPrinter.o \
	src/PlainBoardPrinter.cpp

build/Moves.o: src/Moves.cpp
	@g++ -c -Wall -Werror -o build/Moves.o \
    src/Moves.cpp

format:
	clang-format -i src/*.cpp src/*.h

clean:
	@rm -f build/*
	@rm -f bin/*

install:
	sudo install ./bin/chessviz /usr/local/bin

uninstall:
	sudo rm -rf /usr/local/bin/chessviz

test: 
	@echo "Compiling tests ..."
	@g++ -Wall -Werror -std=c++1z -Ithirdparty/googletest/include -Ithirdparty/googletest -o bin/${appName}-test \
	thirdparty/googletest/lib/libgtest_main.a \
	 thirdparty/googletest/src/gtest-all.cc \
	test/MovesTest.cpp src/Moves.cpp -pthread \
	&& echo "Done"

.PHONY: all install uninstall format test
