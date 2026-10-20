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


bool ftCheckSpecFloat(const std::string &param){
	if (param == "nanf" || param == "+inff" || param == "-inff"){
	  std::cout << "C'est un float spécial" << std::endl;
	  return (true);
    //return param == "nan" || param == "+inf" || param == "-inf";
	} else {
		return (false);
	}
}

bool ftCheckSpecDouble(const std::string &param){
	if (param == "nan" || param == "+inf" || param == "-inf"){
	  std::cout << "C'est un double spécial" << std::endl;
	  return (true);
    //return param == "nan" || param == "+inf" || param == "-inf";
	} else {
		return (false);
	}
}

void ftCheckFloat(const std::string &param){
	size_t i = 0;
	int points = 0;
	int chiffres = 0;
	int f = 0;

	// Signe du début
	if (param[0] == '+' || param[0] == '-'){
		i++;
	}

	// Si aucun chiffre ne suit le signe
	if (i == param.length()){
		std::cout << "Ce n'est pas un float" << std::endl;
		return ;
	}

	if (ftCheckSpecFloat(param) == true){
		return ;
	}

	while (i < param.length() - 1){
		if (param[i] >= '0' && param[i] <= '9'){
			chiffres ++;
		} else if (param[i] == '.'){
			points ++;
		} else {
			std::cout << "Ce n'est pas un float" << std::endl;
			return; 
		}
		i++;
	}

	if (param[param.length() - 1] == 'f'){
		f ++;
	}

	// Si c'est exactement un point et au moins un chiffre
	if (points == 1 && chiffres > 0 && f == 1){
		std::cout << "C'est un float" << std::endl;
	} else {
		std::cout << "Ce n'est pas un float " << std::endl;
	}
}

void ftCheckDouble(const std::string &param){
	size_t i = 0;
	int points = 0;
	int chiffres = 0;

	// Signe du début
	if (param[0] == '+' || param[0] == '-'){
		i++;
	}

	// Si aucun chiffre ne suit le signe
	if (i == param.length()){
		std::cout << "Ce n'est pas un double" << std::endl;
		return ;
	}

	if (ftCheckSpecDouble(param) == true){
		return ;
	}

	while (i < param.length()){
		if (param[i] >= '0' && param[i] <= '9'){
			chiffres ++;
		} else if (param[i] == '.'){
			points ++;
		} else {
			std::cout << "Ce n'est pas un double" << std::endl;
			return; 
		}
		i++;
	}

	// Si c'est exactement un point et au moins un chiffre
	if (points == 1 && chiffres > 0){
		std::cout << "C'est un double" << std::endl;
	} else {
		std::cout << "Ce n'est pas un double " << std::endl;
	}
}

// entier + signe (check les caracter invalide surtout)
void	ftCheckInt(const std::string &param){
	size_t i = 0;

	// Signe du début
	if (param[0] == '+' || param[0] == '-'){
		i++;
	}

	// Si aucun chiffre ne suit le signe
	if (i == param.length()){
		std::cout << "Ce n'est pas un entier" << std::endl;
		return ;
	}

	for (; i < param.length(); i++){
		if (param[i] < '0' || param[i] > '9'){
			std::cout << "Ce n'est pas un entier" << std::endl;
			return ;
		}
	}
	std::cout << "C'est un entier" << std::endl;
}

// caractere
void ftCheckChar(const std::string &param){
	if (param.length() == 1 && !(param[0] >= '0' && param[0] <= '9')){
		char value = param[0];

    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;

		std::exit(EXIT_SUCCESS);
	}
}

void ftCheckNotEmpty(const std::string &param){

	if (param.empty()){
		std::cout << " Agument vide" << std::endl;
    std::exit(EXIT_FAILURE);
	}
}

void ScalarConverter::convert(const std::string &param){
	std::cout << "Argument reçu : " << param << std::endl;

	ftCheckNotEmpty(param);
	ftCheckChar(param);
	ftCheckInt(param);
	ftCheckDouble(param);
	ftCheckFloat(param);

}