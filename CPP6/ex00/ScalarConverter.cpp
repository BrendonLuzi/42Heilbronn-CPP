#include "ScalarConverter.hpp"
#include <iostream>
#include <cerrno>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

int		digittoint(const char c)
{
	return (c - '0');
}

int		o_atoi(const std::string input)
{
	int result = 0;
	int length = input.length() - 1;
	int sign = (input[0] == '-' || input[0] == '+');

	for (int i = sign; i <= length; i++)
	{
		if (INT_MAX / 10 < result)
			throw std::overflow_error("Int overflow.");
		result *= 10;
		if (INT_MAX - digittoint(input[i]) < result - (input[0] == '-'))
			throw std::overflow_error("Int overflow.");
		result += digittoint(input[i]);
	}
	if (input[0] == '-')
		result *= -1;
	return (result);
}

bool	findWrongPlusMinus(const std::string input)
{
	if ((input.find_first_of('+') != std::string::npos)
		&& (input.find_first_of('-') != std::string::npos))
		return true;
	if (input.find_first_of('+') != std::string::npos)
	{
		if (input.find_first_of('+') != input.find_last_of('+'))
			return true;
		if (input.find_first_of('+') != 0)
			return true;
	}
	if (input.find_first_of('-') != std::string::npos)
	{
		if (input.find_first_of('-') != input.find_last_of('-'))
			return true;
		if (input.find_first_of('-') != 0)
			return true;
	}
	return false;
}

void	printOverflow()
{
	std::cout << "Char:\t" << "impossible" << std::endl;
	std::cout << "Int:\t" << "impossible" << std::endl;
	std::cout << "Float:\t" << "impossible" << std::endl;
	std::cout << "Double:\t" << "impossible" << std::endl;
}

void	printChar(char value)
{
	std::cout << "Char:\t";
	if (isprint(value))
		std::cout << '\'' << value << '\'' << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "Int:\t" << static_cast<int>(value) << std::endl;
	std::cout << "Float:\t" << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "Double:\t" << static_cast<double>(value) << std::endl;
}

void	printInt(int value)
{
	if (value > static_cast<int>(CHAR_MAX) || value < 0)
		std::cout << "Char:\t" << "impossible" << std::endl;
	else
	{
		std::cout << "Char:\t";
		if (isprint(value))
			std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "Int:\t" << value << std::endl;
	std::cout << "Float:\t" << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "Double:\t" << static_cast<double>(value) << std::endl;
}

void	printFloat(float value)
{
	if (value == HUGE_VALF || value == -HUGE_VALF)
	{
		printOverflow();
		return ;
	}
	if (value > static_cast<float>(CHAR_MAX) || value < 0)
		std::cout << "Char:\t" << "impossible" << std::endl;
	else
	{
		std::cout << "Char:\t";
		if (isprint(value))
			std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	if (value > static_cast<float>(INT_MAX) || value < static_cast<float>(INT_MIN))
		std::cout << "Int:\t" << "impossible" << std::endl;
	else
		std::cout << "Int:\t" << static_cast<int>(value) << std::endl;
	std::cout << "Float:\t" << value << 'f' << std::endl;
	std::cout << "Double:\t" << static_cast<double>(value) << std::endl;
}

void	printDouble(double value)
{
	if (value == HUGE_VAL || value == -HUGE_VAL)
	{
		printOverflow();
		return ;
	}
	if (value > static_cast<double>(CHAR_MAX) || value < 0)
		std::cout << "Char:\t" << "impossible" << std::endl;
	else
	{
		std::cout << "Char:\t";
		if (isprint(value))
			std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
		std::cout << "Int:\t" << "impossible" << std::endl;
	else
		std::cout << "Int:\t" << static_cast<int>(value) << std::endl;
	if (value > static_cast<double>(MAXFLOAT) || value < static_cast<double>(-MAXFLOAT))
		std::cout << "Float:\t" << "impossible" << std::endl;
	else
		std::cout << "Float:\t" << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "Double:\t" << value << std::endl;
}

bool	checkPseudoLiterals(const std::string input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "Char:\t" << "impossible" << std::endl;
		std::cout << "Int:\t" << "impossible" << std::endl;
		std::cout << "Float:\t" << "nanf" << std::endl;
		std::cout << "Double:\t" << "nan" << std::endl;
		return true;
	}
	else if (input == "inf" || input == "inff")
	{
		std::cout << "Char:\t" << "impossible" << std::endl;
		std::cout << "Int:\t" << "impossible" << std::endl;
		std::cout << "Float:\t" << "inff" << std::endl;
		std::cout << "Double:\t" << "inf" << std::endl;
		return true;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "Char:\t" << "impossible" << std::endl;
		std::cout << "Int:\t" << "impossible" << std::endl;
		std::cout << "Float:\t" << "-inff" << std::endl;
		std::cout << "Double:\t" << "-inf" << std::endl;
		return true;
	}
	return false;
}

void	ScalarConverter::convert(const std::string input)
{
	std::cout << std::fixed;
	if (checkPseudoLiterals(input))
		return ;
	else if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		printChar(input[0]);
	else if (!findWrongPlusMinus(input))
	{
		if (input.find_first_not_of("+-0123456789") == std::string::npos)
		{
			int value;
			try
			{
				value = o_atoi(input);
			}
			catch(...)
			{
				printOverflow();
				return ;
			}
			printInt(value);
		}
		else if (input.find_first_not_of(".+-0123456789") == std::string::npos && input.find_first_of('.') != std::string::npos && input.find_first_of('.') == input.find_last_of('.') && input.find_first_of("0123456789") != std::string::npos)
			printDouble(strtod(input.c_str(), NULL));
		else if (input.find_first_not_of("f.+-0123456789") == std::string::npos && input.find_first_of('f') != std::string::npos && !input[input.find('f') + 1] && input.find_first_of('.') == input.find_last_of('.') && input.find_first_of('.') != std::string::npos && input.find_first_of("0123456789") != std::string::npos)
			printFloat(strtof(input.c_str(), NULL));
		else
			std::cout << "Invalid input" << std::endl;
	}
	else
		std::cout << "Invalid input" << std::endl;
}
