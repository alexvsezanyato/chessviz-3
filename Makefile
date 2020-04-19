default: build 

build:
	c++ -Wall main.cpp -o chessviz

clean:
	rm -f chessviz

rebuild: clean build
