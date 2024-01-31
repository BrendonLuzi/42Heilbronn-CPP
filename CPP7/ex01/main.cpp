#include "iter.hpp"
#include <iostream>

void	increment(int &i)
{
	i++;
}

void	toupper(char &c)
{
	c = std::toupper(c);
}

int main(void)
{
	int			integer_array[5] = { 1, 2, 3, 4, 5 };
	char	char_array[5] = { 'a', 'b', 'c', 'd', 'e' };

	std::cout << std::endl;
	std::cout << "Integer array: ";
	for (int i = 0; i < 5; i++)
		std::cout << integer_array[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Char array: ";
	for (int i = 0; i < 5; i++)
		std::cout << char_array[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl << "Iterating through the arrays..." << std::endl << std::endl;
	::iter(integer_array, 5, increment);
	::iter(char_array, 5, toupper);

	std::cout << "Integer array: ";
	for (int i = 0; i < 5; i++)
		std::cout << integer_array[i] << " ";
	std::cout << std::endl;

	std::cout << "Char array: ";
	for (int i = 0; i < 5; i++)
		std::cout << char_array[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}
