#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("Presidential pardon", "No target", 25, 5)
{
	std::cout << YEL << "PresidentialPardonForm default constructor called" << RST << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
		AForm("Presidential pardon", target, 25, 5)
{
	std::cout << YEL << "PresidentialPardonForm paramaterized constructor called" << RST << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy) :
		AForm("Presidential pardon", copy.getTarget(), 25, 5)
{
	std::cout << YEL << "PresidentialPardonForm copy constructor called" << RST << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLU << "PresidentialPardonForm destructor called" << RST << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm& copy)
{
	this->setSigned(copy.getSigned());
	return (*this);
}

void		PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by president Zaphod Beeblebrox.";
	std::cout << std::endl;
}
