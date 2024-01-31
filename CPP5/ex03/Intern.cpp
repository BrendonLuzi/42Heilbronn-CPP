#include "Intern.hpp"

Intern::Intern()
{
	std::cout << YEL << "Intern default constructor called" << RST << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << YEL << "Intern copy constructor called" << RST << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << BLU << "Intern destructor called" << RST << std::endl;
}

Intern& Intern::operator=(const Intern& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

AForm*	Intern::ShrubberyCreationFormFactory(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::RobotomyrequestFormFactory(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::PresidentialPardonFormFactory(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string name, const std::string target)
{
	AForm *(Intern::* funcs[3])(const std::string target) = {
			&Intern::ShrubberyCreationFormFactory,
			&Intern::RobotomyrequestFormFactory,
			&Intern::PresidentialPardonFormFactory
	};
	std::string formName[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};
	int i = 0;
	while ((formName[i]).compare(name) && i < 3)
		i++;
	if (i < 3)
	{
		std::cout << "Intern succesfully created the " << name << " form!" << std::endl;
		return (this->*funcs[i])(target);
	}
	std::cout << "Intern didn't manage to create the " << name << " form!" << std::endl;
	return NULL;
}