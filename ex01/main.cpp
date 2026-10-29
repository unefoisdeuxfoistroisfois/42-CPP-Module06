#include "Serializer.hpp"

void ftPrintDataStruct(Data *data){

	std::cout << " Data struct "<< std::endl;
	std::cout << " number: " << data->number << std::endl;
	std::cout << " name: " << data->name << std::endl;
}

int	main(){

	Data pointer;

	pointer.number = 25;
	pointer.name = "Bradley";

	ftPrintDataStruct(&pointer);

	uintptr_t rawAdress = Serializer::serialize(&pointer);
	Data *restoredPointer = Serializer::deserialize(rawAdress);

  std::cout << "Same pointer: " << (restoredPointer == &pointer) << std::endl; //si les 2 poitneur on la meme adresse

	ftPrintDataStruct(restoredPointer);

	std::cout << std::endl;

	std::cout << "Original pointer: " << &pointer << std::endl;
	std::cout << "Address as integer: " << rawAdress << std::endl;
	std::cout << "Restored pointer: " << restoredPointer << std::endl;

	// avec allocation
	//Data *data = new Data;

	//data->number = 25;
	//data->name = "Bradley";

	//uintptr_t stock = Serializer::serialize(data);
	//Data *restored = Serializer::deserialize(stock);

	//std::cout << "Same pointer: " << (restored == data) << std::endl;
	//std::cout << restored->number << std::endl;
	//std::cout << restored->name << std::endl;

	//delete data;
	return (0);
}