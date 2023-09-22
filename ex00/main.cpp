#include <iomanip>
#include <string>

#include "ScalarConverter.hpp"


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : Invalid args" << std::endl;
		return (1);
	}
	std::string arg(argv[1]);

	std::cout << "Argument = " << arg << std::endl;

	ScalarConverter::convert(arg);

	std::cout << std::endl;

	return (0);
}