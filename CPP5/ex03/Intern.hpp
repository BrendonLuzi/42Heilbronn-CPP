#ifndef CPP_INTERN_HPP
#define CPP_INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RST "\e[0m"

class Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	~Intern();

	Intern& operator=(const Intern& copy);

	AForm*	makeForm(const std::string name, const std::string target);
	AForm*	ShrubberyCreationFormFactory(const std::string target);
	AForm*	RobotomyrequestFormFactory(const std::string target);
	AForm*	PresidentialPardonFormFactory(const std::string target);
};


#endif
