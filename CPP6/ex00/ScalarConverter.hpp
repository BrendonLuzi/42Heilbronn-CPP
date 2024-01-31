#ifndef CPP_SCALARCONVERTER_HPP
#define CPP_SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <climits>
#include <math.h>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& copy);
public:
	static void	convert(const std::string input);	
};


#endif
