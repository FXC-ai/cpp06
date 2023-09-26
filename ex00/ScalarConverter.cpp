#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
	(void) src;
};

ScalarConverter::~ScalarConverter(){};

ScalarConverter & ScalarConverter::operator=(ScalarConverter &rhs)
{
	return rhs;
};

int ScalarConverter::_type = 0;

bool ScalarConverter::isChar(std::string chain)
{
	if (chain.length() == 1 && std::isprint(chain[0]) == 1 && std::isdigit(chain[0]) == 0)
	{
		ScalarConverter::_type = CHAR;
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(std::string chain)
{
	if(chain.length() >= 1 && chain.find_first_not_of("-0123456789") == std::string::npos)
	{
		ScalarConverter::_type = INT;
		return true;
	}
	return false;
}

bool ScalarConverter::isFloat(std::string chain)
{
	if(chain.find('.') != std::string::npos && chain.find('f') != std::string::npos)
	{
		ScalarConverter::_type = FLOAT;
		return true;
	}
	return false;
}

bool ScalarConverter::isDouble(std::string chain)
{
	if(chain.find('.') != std::string::npos && chain.find('f') == std::string::npos)
	{
		ScalarConverter::_type = DOUBLE;
		return true;
	}
	return false;
}

bool ScalarConverter::isNan(std::string chain)
{
	if((chain.compare("nan") == 0) || (chain.compare("nanf") == 0))
	{
		ScalarConverter::_type = UNKNOWN;
		return true;
	}
	return false;
}

bool ScalarConverter::isInf(std::string chain)
{
	return ((chain.compare("-inff") == 0)
			|| (chain.compare("+inff") == 0)
			|| (chain.compare("-inf") == 0)
			|| (chain.compare("+inf") == 0));
}

char ScalarConverter::convertToChar(std::string chain)
{
	return *(chain.c_str());
}

long ScalarConverter::convertToLong(std::string chain)
{

	return std::strtol(chain.c_str(), NULL, 10);
}

float ScalarConverter::convertToFloat(std::string chain)
{
	return std::atof(chain.c_str());
}

double ScalarConverter::convertToDouble(std::string chain)
{
	return std::strtod(chain.c_str(), NULL);
}

void ScalarConverter::display_inf(std::string chain)
{
	std::cout << "char: impossible" <<std::endl;
	std::cout << "int: impossible" <<std::endl;
	std::cout << "float: " << chain <<std::endl;
	std::cout << "double: " << chain <<std::endl;
}

void ScalarConverter::display_nan()
{
	std::cout << "char: impossible" <<std::endl;
	std::cout << "int: impossible" <<std::endl;
	std::cout << "float: nanf" <<std::endl;
	std::cout << "double: nan" <<std::endl;
}

void		ScalarConverter::display_from_char (char c, int i, float f ,double d)
{
	if (std::isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void		ScalarConverter::display_from_int (char c, long i, float f ,double d)
{
	std::cout << "char: ";
	if (i > 31 && i < 127)
	{
		std::cout << "'" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (i < INT_MIN || i > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(i) << std::endl;
	}

	std::cout << "float: ";
	if (i >= -999999 && i <= 999999)
	{
		std::cout << f << ".0f" << std::endl;
	}
	else
	{
		std::cout << f << "f" << std::endl;
	}

	std::cout << "double: ";
	if (i >= -999999 && i <= 999999)
	{
		std::cout << d << ".0" << std::endl;
	}
	else
	{
		std::cout << d << std::endl;
	}

}

void		ScalarConverter::display_from_float (char c, int i, float f ,double d)
{
	std::cout << "char: ";
	if (f > 31 && f < 127)
	{
		std::cout << "'" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (f < INT_MIN || f > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << i << std::endl;
	}

	if (f > INT_MIN && f < INT_MAX)
	{
		std::cout << "float: " << std::to_string(f) << "f" << std::endl;
		std::cout << "double: " << std::to_string(d) << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void		ScalarConverter::display_from_double (char c, int i, float f ,double d)
{
	std::cout << "char: ";
	if (d > 31 && d < 127)
	{
		std::cout << "'" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (d < INT_MIN || d > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << i << std::endl;
	}

	if (d > INT_MIN && d < INT_MAX)
	{
		std::cout << "float: " << std::to_string(f) << "f" << std::endl;
		std::cout << "double: " << std::to_string(d) << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::convert(std::string chain)
{
	if (ScalarConverter::isChar(chain))
	{
		char c = ScalarConverter::convertToChar(chain);
		display_from_char(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
	}
	else if (ScalarConverter::isInt(chain))
	{
		long i = ScalarConverter::convertToLong(chain);
		display_from_int(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
	}
	else if (ScalarConverter::isFloat(chain))
	{
		float f = ScalarConverter::convertToFloat(chain);
		display_from_float(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
	}
	else if (ScalarConverter::isDouble(chain))
	{
		double d = ScalarConverter::convertToDouble(chain);
		display_from_double(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
	}
	else if (ScalarConverter::isInf(chain))
	{
		ScalarConverter::display_inf(chain);
	}
	else
	{
		ScalarConverter::display_nan();
	}
}