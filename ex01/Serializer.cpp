#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src){
	std::cout << "Serializer copy constructor called" << std::endl;

	(void)src;
}

Serializer &Serializer::operator=(const Serializer &rhs){
	std::cout << "Serializer assignment operator called" << std::endl;

	if (this != &rhs){
	}

	return (*this);
}

Serializer::~Serializer(){
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t stock = reinterpret_cast<uintptr_t>(ptr);

	return (stock);
}


Data *Serializer::deserialize(uintptr_t raw){
	Data *newdata = reinterpret_cast<Data *>(raw);

	return (newdata);
}