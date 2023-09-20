// C++ code to demonstrate "to_string()" method
// to convert number to string.
#include <iostream>
#include <string> // for string and to_string()
// using namespace std;

// Driver Code
int main()
{
	// Declaring integer
	int i_val = 20;

	// Declaring float
	float f_val = 30.50;

	// Conversion of int into string using
	// to_string()
	std::string stri = std::to_string(i_val);

	// Conversion of float into string using
	// to_string()
	std::string strf = std::to_string(f_val);

	// Displaying the converted strings
	std::cout << "The integer in string is : ";
	std::cout << stri << std::endl;
	std::cout << "The float in string is : ";
	std::cout << strf << std::endl;

	return 0;
}


