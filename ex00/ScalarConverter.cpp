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
	if (points != 1 || chiffres == 0 || f != 1){
	  return ;
	}

	errno = 0;
	double number = std::strtod(param.c_str(), NULL);

	if (errno == ERANGE || number < -FLT_MAX || number > FLT_MAX){
    std::cout << "Valeur hors limites pour un float" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	float value = static_cast<float>(number);

	if (static_cast<double>(value) < CHAR_MIN || static_cast<double>(value) > CHAR_MAX){
    std::cout << "char: impossible" << std::endl;
	} else if (value < 32 || value >= 127){
    std::cout << "char: Non displayable" << std::endl;
	} else {
   std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}

	if (value < INT_MIN || value > INT_MAX){
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}

	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
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
		} else{
			return; 
		}
		i++;
	}

	if (points != 1 || chiffres == 0){
		return ;
	}

	errno = 0;
	double value = std::strtod(param.c_str(), NULL);

	if (errno == ERANGE){
		std::cout << "Valeur trop grande" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// La valeur peux elle etre afficher par un char si oui est il affichable ?
	if (value < CHAR_MIN || value > CHAR_MAX){
	    std::cout << "char: impossible" << std::endl;
	} else if (value < 32 || value >= 127){
	    std::cout << "char: Non displayable" << std::endl;
	} else{
	    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}

	if (value < INT_MIN || value > INT_MAX){
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}

	if (value < -FLT_MAX || value > FLT_MAX)	{
	  std::cout << "float: impossible" << std::endl;
	} else{
	  std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;

	std::exit(EXIT_SUCCESS);
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
		return ;
	}

	for (; i < param.length(); i++){
		if (param[i] < '0' || param[i] > '9'){
			return ;
		}
	}

	errno = 0;
	long number = std::strtol(param.c_str(), NULL, 10); // chaine en const char *, pas d'endroit ou recup, et base de 0 a 9

	// Verifier que la valeur tien dans un int
	if (errno == ERANGE || number < INT_MIN || number > INT_MAX){
		std::cout << "La valeur est trop grande pour un int" << std::endl;
    std::exit(EXIT_FAILURE);
	}

	int value = static_cast<int>(number);

	// Convertion en char et si caractere affichable
	if (value < CHAR_MIN || value > CHAR_MAX){
    std::cout << "char: impossible" << std::endl;
	} else if (value < 32 || value > 126){
    std::cout << "char: Non displayable" << std::endl;
	} else {
   std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}

	// Convertion autre type
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;

	std::exit(EXIT_SUCCESS);
}

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
	//if (isChar(param))
	//    convertChar(param);
	//else if (isInt(param))
	//    convertInt(param);
	//else if (isFloat(param))
	//    convertFloat(param);
	//else if (isDouble(param))
	//    convertDouble(param);
	//else
	//    std::cout << "Invalid input" << std::endl;
}