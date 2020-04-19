#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
	std::ifstream file;

	if (argc == 2) file.open(argv[1]);
	else 
	{
		std::cout << "Wrong input. Type 'chessviz --help' to get help \n";
		return 1;
	}

	if (!file) 
	{
		std::cout << "Fail to open " << argv[1] << "\n";
		return 1;
	}
}
