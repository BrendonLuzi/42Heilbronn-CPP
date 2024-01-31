//
// Created by Brendon Luzi on 10/25/23.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat	tony("Tony Pizza", 1);
	// Bureaucrat	tony("Tony Pizza but useless", 150);
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Micheal Wave");
	PresidentialPardonForm pardon("Micheal Obama");

	std::cout << std::endl;
	std::cout << tony;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	std::cout << std::endl;

	try
	{
		tony.signForm(shrubbery);
		tony.executeForm(shrubbery);
		tony.signForm(robotomy);
		tony.executeForm(robotomy);
		tony.signForm(pardon);
		tony.executeForm(pardon);
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
