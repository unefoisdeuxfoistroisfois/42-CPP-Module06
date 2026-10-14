#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	std::cout << "ScalarConverter copy constructor called" << std::endl;

	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
	std::cout << "ScalarConverter assignement operator called" << std::endl;

	if (this != &rhs){
	}

	return (*this);
}

ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void	ftInt(const std::string &param){
	for (size_t i = 0; i < param.length(); i++){
		if (param[i] >= '0' && param[i] <= '9' && param[i].is ){
			std::cout << "Ce n'est pas un entier" << std::endl;
			return ;
		}
	}
	std::cout << " C'est un entier" << std::endl;
}

void ftCaract(const std::string &param){
	if (param.length() == 1 && !(param[0] >= '0' && param[0] <= '9')){
		std::cout << "Ceci est un caractere" << std::endl;
		return ;
	}
	else {
		std::cout << "Ceci n'est pas un caractere" << std::endl;
	}
}

void ftIsValide(const std::string &param){

	if (param.empty()){
		std::cout << " Agument vide" << std::endl;
		return ;
	}
}

void ScalarConverter::convert(const std::string &param){
	std::cout << "Argument reçu : " << param << std::endl;

	ftIsValide(param);
	ftCaract(param);
	ftInt(param);
}