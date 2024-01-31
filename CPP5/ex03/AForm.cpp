#include "AForm.hpp"


AForm::AForm() :
	name("No name"),
	target("No name"),
	isSigned(false),
	signGrade(150),
	execGrade(150)
{
	std::cout << YEL << "AForm default constructor called" << RST << std::endl;
}


AForm::AForm(const std::string name, const std::string target, const int signGrade, const int execGrade) :
		name(name),
		target(target),
		isSigned(false),
		signGrade(signGrade),
		execGrade(execGrade)
{
	std::cout << YEL << "Form parameterized constructor called" << RST << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}


AForm::AForm(AForm& copy) :
	name(copy.name),
	target(copy.target),
	isSigned(copy.isSigned),
	signGrade(copy.signGrade),
	execGrade(copy.execGrade)
{
	std::cout << YEL << "AForm copy constructor called" << RST << std::endl;
}

AForm::~AForm()
{
	std::cout << BLU << "AForm destructor called" << RST << std::endl;
}

AForm&	AForm::operator=(AForm& copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

const std::string	AForm::getName() const
{
	return (this->name);
}

const std::string	AForm::getTarget() const
{
	return (this->target);
}

bool 				AForm::getSigned() const
{
	return (this->isSigned);
}

int 				AForm::getSignGrade() const
{
	return (this->signGrade);
}

int 				AForm::getExecGrade() const
{
	return (this->execGrade);
}

void 				AForm::setSigned(bool status)
{
	this->isSigned = status;
}


void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade && !this->isSigned)
	{
		this->isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << this->name << std::endl;
	}
	else
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name;
		std::cout << " because ";
		if (this->isSigned)
		{
			std::cout << "the form is already signed!" << std::endl;
			throw AlreadySignedException();
		}
		std::cout <<" his grade is too low!" << std::endl;
		throw GradeTooLowException();
	}
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->execGrade && this->isSigned)
		std::cout << executor.getName() << " executes the " << this->name << std::endl;
	else
	{
		std::cout << executor.getName() << " couldn't execute the " << this->name;
		std::cout << " because ";
		if (!this->isSigned)
		{
			std::cout << "the form is not signed!" << std::endl;
			throw NotSignedException();
		}
		std::cout <<" his grade is too low!" << std::endl;
		throw GradeTooLowException();
	}
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("The form is already signed!");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed yet!");
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName() << ", ";
	if (form.getSigned())
		out << "signed form ";
	else
		out << "unsigned form ";
	out << "with target " << form.getTarget() << ". ";
	out << "Required grade to sign: " << form.getSignGrade() << ". ";
	out << "Required grade to execute: " << form.getExecGrade() << ".";
	out << std::endl;
	return (out);
}
