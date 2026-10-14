#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream> 
#include <string> 
#include <exception> 

class ScalarConverter{
	private:
		/**
		 * permet d'empecher l'instance
		 */
		// FCO
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();

	public: 

		static void convert(const std::string &param);
};

#endif