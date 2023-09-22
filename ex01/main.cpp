#include "serializer.hpp"



Serializer::Serializer(){};
Serializer::~Serializer(){};
Serializer::Serializer(Serializer &src)
{
	(void) src;
}

Serializer &Serializer::operator=(Serializer &rhs)
{
	return rhs;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main ()
{

	// Declaration Variable origin de type Data
	Data origin;
	origin.x = 0;
	origin.y = 0;
	origin.z = 0;

	// Valeur du pointeur de origin avant serialisation
	std::cout << "Pointeur sur origin AVANT serialization = " << &origin << std::endl;

	// Serialization
	uintptr_t originPtr_serialized = Serializer::serialize(&origin);
	std::cout << "Pointeur sur origin APRES serialization = " << originPtr_serialized << std::endl;

	// Deserialization
	Data *originPtr = Serializer::deserialize(originPtr_serialized);
	std::cout << "Pointeur sur origin APRES deserialization = " << Serializer::deserialize(originPtr_serialized) << std::endl;

	// Dernier check
	std::cout << "x = " << originPtr->x << std::endl;
	std::cout << "y = " << originPtr->y << std::endl;
	std::cout << "z = " << originPtr->z << std::endl;



	return 0;
}
