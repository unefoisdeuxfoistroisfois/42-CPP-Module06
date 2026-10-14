#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
	std::cout << "ScalarConverter assignement operator called" << std::endl;

	if (this != &rhs){
		return (*this);
	}

	return (*this);
}

ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string &param){

}