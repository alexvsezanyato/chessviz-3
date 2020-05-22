# app

appName := chessviz

objects += build/Board.o
objects += build/PlainBoardPrinter.o
objects += build/Moves.o

all: bin/${appName}

bin/${appName}: build/Main.o ${objects}
	@g++ -Wall -Werror -std=c++1z -o bin/${appName} build/Main.o ${objects}

build/Main.o: src/Main.cpp
	@g++ -c -Wall -Werror -std=c++1z -o build/Main.o \
	src/Main.cpp

build/Board.o: src/Board.cpp
	@g++ -c -Wall -Werror -std=c++1z -o build/Board.o \
	src/Board.cpp

build/PlainBoardPrinter.o: src/PlainBoardPrinter.cpp
	@g++ -c -Wall -Werror -std=c++1z -o build/PlainBoardPrinter.o \
	src/PlainBoardPrinter.cpp

build/Moves.o: src/Moves.cpp
	@g++ -c -Wall -Werror -std=c++1z -o build/Moves.o \
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

# test

testName := ${appName}-test

testObjects := build/test/BoardTest.o
testObjects += build/test/MovesTest.o

gtestPath = thirdparty/googletest

test: ${testObjects}
	@echo "Compiling tests ..."
	@g++ -Wall -Werror -std=c++1z -o bin/${testName} \
	 -I ${gtestPath}/include -I ${gtestPath} \
	 ${gtestPath}/lib/libgtest_main.a \
	 ${gtestPath}/src/gtest-all.cc \
	 ${testObjects} ${objects} -pthread && echo "Done"

build/test/BoardTest.o: test/BoardTest.cpp
	@g++ -c -Wall -Werror -std=c++1z -o build/test/BoardTest.o \
	 -I ${gtestPath}/include -I ${gtestPath} -I src \
	 test/BoardTest.cpp

build/test/MovesTest.o: test/MovesTest.cpp
	@g++ -c -Wall -Werror -std=c++1z -o build/test/MovesTest.o \
	 -I ${gtestPath}/include -I ${gtestPath} -I src \
	 test/MovesTest.cpp

.PHONY: all install uninstall format test
