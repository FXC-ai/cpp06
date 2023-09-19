#include <iostream>

class testCast 
{

	public :
		testCast(const float v) : _v(v)
		{
		} 

		float getV(){return this->_v;}

		operator float() {return this->_v;}
		operator int() {return static_cast<int>(this->_v);}

	private :
		const float _v;
};

int main()
{
	testCast testCast1(420.234001f);

	int a = testCast1;
	float b = testCast1;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}


