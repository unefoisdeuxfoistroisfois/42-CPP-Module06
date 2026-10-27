#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream> 
#include <string> 
#include <cstdlib>
#include <climits>
#include <cfloat>

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