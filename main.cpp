#include <iostream>
#include <string>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define UNKNOWN 5


class ScalarConverter
{
	private :
		ScalarConverter();
	// 	static std::string _chain;
	// 	static std::string _type;


	public:
		//ScalarConverter(const std::string chain);
		//std::string getChain(std::string chain);
		static bool	isChar(std::string chain);
		static bool	isDouble(std::string chain);
		static bool	isInt(std::string chain);
		static bool	isFloat(std::string chain);
		static bool	isNan(std::string chain);
		static bool	isInf(std::string chain);

		static double	convertToDouble(std::string chain);
		static float	convertToFloat(std::string chain);
		static char	convertToChar(std::string chain);
		static long	convertToLong(std::string chain);


		static void convert(std::string);
		// void		setType();
		// std::string getType();

};

// ScalarConverter::ScalarConverter(std::string chain)
// {
// 	this->_chain = chain;

// } 

// std::string ScalarConverter::getChain()
// {
// 	return this->_chain;
// }

ScalarConverter::ScalarConverter(){};

bool ScalarConverter::isChar(std::string chain)
{
	return (chain.length() == 1 && std::isprint(chain[0]) == 1);
}

bool ScalarConverter::isDouble(std::string chain)
{
	return (chain.find('.') == 1 && chain.find('f') == std::string::npos);
}

bool ScalarConverter::isInt(std::string chain)
{
	return (chain.length() > 1 && chain.find_first_not_of("-0123456789") == std::string::npos);
}

bool ScalarConverter::isFloat(std::string chain)
{
	return (chain.find('.') == 1 && chain.find('f') != std::string::npos);
}

bool ScalarConverter::isNan(std::string chain)
{
	return ((chain.compare("nan") == 0) || (chain.compare("nanf") == 0));
}

bool ScalarConverter::isInf(std::string chain)
{
	return ((chain.compare("-inff") == 0)
			|| (chain.compare("+inff") == 0)
			|| (chain.compare("-inf") == 0)
			|| (chain.compare("+inf") == 0));
}

double ScalarConverter::convertToDouble(std::string chain)
{
	return std::strtod(chain.c_str(), NULL);
}

float ScalarConverter::convertToFloat(std::string chain)
{
	return std::atof(chain.c_str());
}

char ScalarConverter::convertToChar(std::string chain)
{
	return *(chain.c_str());
}

long ScalarConverter::convertToLong(std::string chain)
{
	return std::strtol(chain.c_str(), NULL, 10);
}

// void ScalarConverter::setType()
// {
// 	if (this->isChar(this_))



// }


void ScalarConverter::convert(std::string chain)
{

	if (ScalarConverter::isChar(chain))
	{
		std::cout << chain << " char" <<std::endl;
	}





}


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

	//2147483647
	//–2147483648


	// const std::string chain = "k";
	// ScalarConverter SCobjChar(chain);
	// //std::cout << SCobjChar.isChar() << std::endl;
	// std::cout << SCobjChar.convertToChar() << std::endl;

	// const std::string chain1 = "2.39879";
	// ScalarConverter SCobjDouble(chain1);
	// //std::cout << SCobjDouble.isDouble() << std::endl;
	// std::cout << SCobjDouble.convertToDouble() << std::endl;

	// const std::string chain2("21474836470");
	// ScalarConverter SCobjInt(chain2);
	// //std::cout << SCobjInt.isInt() << std::endl;
	// std::cout << "INT : " << SCobjInt.convertToLong() << std::endl;

	// const std::string chain3("2.3558905f");
	// ScalarConverter SCobjFloat(chain3);
	// //std::cout << SCobjFloat.isFloat() << std::endl;
	// std::cout << SCobjFloat.convertToFloat() << std::endl;

	// const std::string chain4("nan");
	// ScalarConverter SCobjNan(chain4);
	// //std::cout << SCobjNan.isNan() << std::endl;

	// const std::string chain5("-inf");
	// ScalarConverter SCobjInf(chain5);
	// //std::cout << SCobjInf.isInf() << std::endl;

	// double test = std::numeric_limits<int>::min();
	// std::cout << test << std::endl;

	// test = std::numeric_limits<int>::max();
	// std::cout << "max = " << test << std::endl;


	// float test1 = std::numeric_limits<float>::min();

	// std::cout << test1 << std::endl;
	// std::cout << std::endl;




	return (0);
}