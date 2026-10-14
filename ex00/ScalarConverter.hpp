#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream> 
#include <string.h> 
#include <exception> 

class ScalarConverter{
	private:

	public: 
		// FCO
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();

		static void convert(const std::string &param);
};

#endif