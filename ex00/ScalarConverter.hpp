#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

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
		static int _type;

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

#endif