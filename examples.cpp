#include <iostream>

class A{};
class B{};

class C
{
	public :
		C(A const &_){}
		explicit C(B const &_){}
};

void f(C const &_)
{
	std::cout << "OK" << std::endl;
	return;
}


int main()
{

	f( A() );
	f( B() );


	return 0;
}


