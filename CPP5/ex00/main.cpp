#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat tony("Tony Pizza", 1);
	Bureaucrat johnny("Johnny Peperoni", 150);

	std::cout << std::endl;
	std::cout << tony;
	std::cout << johnny;
	std::cout << std::endl;

	try
	{
//		Bureaucrat impossible("Impossible", 0);

		johnny.promote();
//		johnny.demote();

		tony.demote();
//		tony.promote();

		std::cout << std::endl;

		std::cout << tony;
		std::cout << johnny;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception thrown: ";
		std::cerr << e.what() << RST << std::endl << std::endl;
		return(1);
	}
	std::cout << std::endl;

	return (0);
}