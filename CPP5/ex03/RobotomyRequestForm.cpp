#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("Robotomy request", "No target", 72, 45)
{
	std::cout << YEL << "RobotomyRequestForm default constructor called" << RST << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
		AForm("Robotomy request", target, 72, 45)
{
	std::cout << YEL << "RobotomyRequestForm paramaterized constructor called" << RST << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy) :
		AForm("Robotomy request", copy.getTarget(), 72, 45)
{
	std::cout << YEL << "RobotomyRequestForm copy constructor called" << RST << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BLU << "RobotomyRequestForm destructor called" << RST << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm& copy)
{
	this->setSigned(copy.getSigned());
	return (*this);
}

void		RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	srand(time(NULL));
	std::cout << "Bzzzzzzzzzzzzzzzzzz... ";
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been succesfully robotomized!" << std::endl;
	else
		std::cout << "The robotomy on " << this->getTarget() << " failed!" << std::endl;
}
