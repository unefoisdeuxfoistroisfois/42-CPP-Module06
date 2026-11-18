#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]){

	if (argc != 2){
		std::cerr << "One argument required" << std::endl;

		return (-1);
	}
	
	/**
	 * j'avais un soucis avec les exit donc
	 * j'ai mis un static car flemme de changer toutmon code
	 */
	static const std::string input(argv[1]);
	ScalarConverter::convert(argv[1]);

	return (0);
}