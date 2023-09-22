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
		ScalarConverter(ScalarConverter & src);
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter &rhs);

	public:
		static bool		isChar(std::string chain);
		static bool		isInt(std::string chain);
		static bool		isFloat(std::string chain);
		static bool		isDouble(std::string chain);
		static bool		isNan(std::string chain);
		static bool		isInf(std::string chain);

		static double	convertToDouble(std::string chain);
		static float	convertToFloat(std::string chain);
		static char		convertToChar(std::string chain);
		static long		convertToLong(std::string chain);

		static void 	convert(std::string);
		static void 	display(char c, long i, float f, double d);

		static void		display_char(char c);
		static void		display_int(long l);
		static void		display_float(float l);
		static void		display_double(double d);
		static void		display_inf(std::string chain);
		static void		display_nan();
};

ScalarConverter::ScalarConverter(){};

ScalarConverter::~ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
	(void) src;
};

ScalarConverter & ScalarConverter::operator=(ScalarConverter &rhs)
{
	return rhs;
};

bool ScalarConverter::isChar(std::string chain)
{
	return (chain.length() == 1 && std::isprint(chain[0]) == 1 && std::isdigit(chain[0]) == 0);
}

char ScalarConverter::convertToChar(std::string chain)
{
	return *(chain.c_str());
}

bool ScalarConverter::isInt(std::string chain)
{
	return (chain.length() >= 1 && chain.find_first_not_of("-0123456789") == std::string::npos);
}

bool ScalarConverter::isDouble(std::string chain)
{
	return (chain.find('.') != std::string::npos && chain.find('f') == std::string::npos);
}

bool ScalarConverter::isFloat(std::string chain)
{
	return (chain.find('.') != std::string::npos && chain.find('f') != std::string::npos);
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

long ScalarConverter::convertToLong(std::string chain)
{
	return std::strtol(chain.c_str(), NULL, 10);
}

void ScalarConverter::display_char(char c)
{
	if (std::isprint(c) == 1)
	{
		std::cout << "char: '" << c << "'" << std::endl;
	}
	// else if (c < 0)
	// {
	// 	std::cout << "char: Non displayable" << std::endl;
	// }
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::display_int(long l)
{
	std::cout << "int: ";
	if (l > INT_MAX || l < INT_MIN)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(l) << std::endl;
	}
}

void ScalarConverter::display_float(float f)
{
	std::cout << "float: ";
	std::cout << f;

	if ((f - static_cast<int>(f)) == 0)
	{
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void ScalarConverter::display_double(double d)
{
	std::cout << "double: ";
	std::cout << d << std::endl;
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

void ScalarConverter::display(char c, long i, float f, double d)
{
	ScalarConverter::display_char(c);
	ScalarConverter::display_int(i);
	ScalarConverter::display_float(f);
	ScalarConverter::display_double(d);
}

void ScalarConverter::convert(std::string chain)
{
	if (ScalarConverter::isChar(chain))
	{
		char c = ScalarConverter::convertToChar(chain);
		display(c, static_cast<long>(c), static_cast<float>(c), static_cast<double>(c));
	}
	else if (ScalarConverter::isInt(chain))
	{
		long i = ScalarConverter::convertToLong(chain);

		if (i > 127 && static_cast<char>(i) <= 127)
		{
			display(-1, i, static_cast<float>(i), static_cast<double>(i));
		}
		else
		{
			display(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
		}
	}
	else if (ScalarConverter::isFloat(chain))
	{
		float f = ScalarConverter::convertToFloat(chain);
		display(static_cast<char>(f), static_cast<long>(f), f, static_cast<double>(f));
	}
	else if (ScalarConverter::isDouble(chain))
	{
		double d = ScalarConverter::convertToDouble(chain);
		display(static_cast<char>(d), static_cast<long>(d), static_cast<float>(d), d);
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
	//2147483647
	//–2147483648

	return (0);
}