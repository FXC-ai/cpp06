#include "Serializer.hpp"

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
