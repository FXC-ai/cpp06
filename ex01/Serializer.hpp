#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "data.h"


class Serializer 
{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer &src);
		Serializer &operator=(Serializer &rhs);

	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif