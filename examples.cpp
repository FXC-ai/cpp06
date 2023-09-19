#include <iostream>

class Parent {public: virtual ~Parent(){};};
class Child1: public Parent{};
class Child2: public Parent{};


class Unrelated {};

int main()
{

	Child1 a;
	Parent *b = &a;

	Child1 *c = dynamic_cast<Child1 *>(b);

	if (c == NULL)
	{
		std::cout << "Tous va bien" << std::endl;
	}
	else
	{
		std::cout << "Marche pas" << std::endl;
	}

	try
	{
		Child2 & d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion works" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cout << bc.what() << std::endl;
		return 0;
	}

	return 0;
}


