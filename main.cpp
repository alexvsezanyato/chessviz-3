#include <fstream>
#include <iostream>

int main()
{
	std::ifstream file("source/input");

	if (!file) 
	{
		std::cout << "Fail to open source/input \n";
		return 1;
	}
}
