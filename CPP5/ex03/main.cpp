#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat	joe("Joe", 1);
//	Bureaucrat	mama("Mama", 150);
//	ShrubberyCreationForm s_form("home");
//	RobotomyRequestForm r_form("Micheal Wave");
//	PresidentialPardonForm p_form("Micheal Obama");
	Intern intern;

	std::cout << joe;
//	std::cout << mama;
//	std::cout << s_form;
//	std::cout << r_form;
//	std::cout << p_form;

	try
	{
//		joe.signForm(s_form);
//		joe.executeForm(s_form);
//		joe.signForm(r_form);
//		joe.executeForm(r_form);
		AForm* form;
		form = intern.makeForm("presidential pardon", "Micheal Wave");
		// form = intern.makeForm("i don't know", "whoever");
		if (form)
		{
			joe.signForm(*form);
			joe.executeForm(*form);

			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception thrown: ";
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return (0);
}
