#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

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

		static char		convertToChar(std::string chain);
		static long		convertToLong(std::string chain);
		static float	convertToFloat(std::string chain);
		static double	convertToDouble(std::string chain);

		static void		display_inf(std::string chain);
		static void		display_nan();

		static void		display_from_char (char c, int i, float f ,double d);
		static void		display_from_int (char c, long i, float f ,double d);
		static void		display_from_float (char c, int i, float f ,double d);
		static void		display_from_double (char c, int i, float f ,double d);

		static void 	convert(std::string);
};

#endif