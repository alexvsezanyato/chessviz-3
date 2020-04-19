#include <fstream>
#include <iostream>

int main()
{
	ifstream file("source/input");

	if (!file) 
	{
		std::cout << "Fail to open source/input";
		return 1;
	}
}
