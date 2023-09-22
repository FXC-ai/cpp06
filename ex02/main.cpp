#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(0));
	int temp = rand() % 3;
	if (temp == 0)
	{
		return new A();
	}
	else if (temp == 1)
	{
		return new B();
	}
	else
	{
		return new C();
	}

}

void identify(Base* p)
{
	A *testA = dynamic_cast<A*>(p);
	if (testA != nullptr)
	{
		std::cout << "A" << std::endl;
	}

	B *testB = dynamic_cast<B*>(p);
	if (testB != nullptr)
	{
		std::cout << "B" << std::endl;
	}

	C *testC = dynamic_cast<C*>(p);
	if (testC != nullptr)
	{
		std::cout << "C" << std::endl;
	}

}

void identify(Base& p)
{

	try
	{
		A& testA = dynamic_cast<A&>(p);
		(void) testA;
		std::cout << "A" << std::endl;	
	}
	catch (const std::bad_cast &bc)
	{		
	}

	try
	{
		B& testB = dynamic_cast<B&>(p);
		(void) testB;

		std::cout << "B" << std::endl;	
	}
	catch (const std::bad_cast &bc)
	{		
	}

	try
	{
		C& testC = dynamic_cast<C&>(p);
		(void) testC;

		std::cout << "C" << std::endl;	
	}
	catch (const std::bad_cast &bc)
	{		
	}	
}

int main()
{

	Base *randomABC = generate();

	identify(randomABC);
	identify(*randomABC);

	delete randomABC;

	return 0;
}