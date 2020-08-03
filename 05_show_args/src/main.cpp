#include <iostream>

int main(int argc, char *argv[])
{
	for (int contor = 0; contor < argc; contor++)
	{
		std::cout << argv[contor] << "\n" << std::endl;
	}
	
	return 0;
}