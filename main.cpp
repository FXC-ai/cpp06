#include <iostream>


class ScalarConverter
{
	private :
		const std::string _chain;

	public:
		ScalarConverter(const std::string chain);
		std::string getChain();
		bool	isChar();
		bool	isDouble();
		bool	isInt();
		bool	isFloat();
		bool	isNan();
		bool	isInf();

		double	convertToDouble();
		float	convertToFloat();
		char	convertToChar();
		int		convertToInt();
};

ScalarConverter::ScalarConverter(std::string chain) : _chain(chain){} 

std::string ScalarConverter::getChain()
{
	return this->_chain;
}

bool ScalarConverter::isChar()
{
	return (this->_chain.length() == 1 && std::isprint(_chain[0]) == 1);
}

bool ScalarConverter::isDouble()
{
	return (this->_chain.find('.') == 1 && this->_chain.find('f') == std::string::npos);
}

bool ScalarConverter::isInt()
{
	return (this->_chain.length() > 1 && this->_chain.find_first_not_of("-0123456789") == std::string::npos);
}

bool ScalarConverter::isFloat()
{
	return (this->_chain.find('.') == 1 && this->_chain.find('f') != std::string::npos);
}

bool ScalarConverter::isNan()
{
	return ((this->_chain.compare("nan") == 0) || (this->_chain.compare("nanf") == 0));
}

bool ScalarConverter::isInf()
{
	return ((this->_chain.compare("-inff") == 0)
			|| (this->_chain.compare("+inff") == 0)
			|| (this->_chain.compare("-inf") == 0)
			|| (this->_chain.compare("+inf") == 0));
}

double ScalarConverter::convertToDouble()
{
	return std::stod(this->_chain);
}

float ScalarConverter::convertToFloat()
{
	return std::atof(this->_chain.c_str());
}

char ScalarConverter::convertToChar()
{
	return *(this->_chain.c_str());
}

int ScalarConverter::convertToInt()
{
	return std::atoi(this->_chain.c_str());
}

int main()
{
	const std::string chain = "k";
	ScalarConverter SCobjChar(chain);
	std::cout << SCobjChar.isChar() << std::endl;
	std::cout << SCobjChar.convertToChar() << std::endl;

	const std::string chain1 = "2.39879";
	ScalarConverter SCobjDouble(chain1);
	std::cout << SCobjDouble.isDouble() << std::endl;
	std::cout << SCobjDouble.convertToDouble() << std::endl;

	const std::string chain2("6789");
	ScalarConverter SCobjInt(chain2);
	std::cout << SCobjInt.isInt() << std::endl;
	std::cout << SCobjInt.convertToInt() << std::endl;

	const std::string chain3("2.3558905f");
	ScalarConverter SCobjFloat(chain3);
	std::cout << SCobjFloat.isFloat() << std::endl;
	std::cout << SCobjFloat.convertToFloat() << std::endl;

	const std::string chain4("nan");
	ScalarConverter SCobjNan(chain4);
	std::cout << SCobjNan.isNan() << std::endl;

	const std::string chain5("-inf");
	ScalarConverter SCobjInf(chain5);
	std::cout << SCobjInf.isInf() << std::endl;

	//std::cout << static_cast<int>(chain2.c_str()) << std::endl;

	return (0);
}