#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	tony("Tony Pizza", 1);
	Bureaucrat	johnny("Johnny Peperoni", 150);
	Form		form("FTG2H", 20, 1);
	Form		anotherForm("FTG10K", 149, 1);

	std::cout << std::endl;
	std::cout << tony;
	std::cout << johnny;
	std::cout << form;
	std::cout << anotherForm;
	std::cout << std::endl;


	try
	{
		// Form	impossibleForm("Impossible", 0, 0);

		tony.signForm(form);

		johnny.signForm(anotherForm);
		johnny.promote();
		johnny.signForm(anotherForm);

		tony.signForm(form);
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