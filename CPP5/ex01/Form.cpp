#include "Form.hpp"


Form::Form() :
	name("No name"),
	isSigned(false),
	signGrade(150),
	execGrade(150)
{
	std::cout << YEL << "Form default constructor called" << RST << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) :
	name(name),
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

Form::Form(Form& copy) :
	name(copy.name),
	isSigned(copy.isSigned),
	signGrade(copy.signGrade),
	execGrade(copy.execGrade)
{
	std::cout << YEL << "Form copy constructor called" << RST << std::endl;
}

Form::~Form()
{
	std::cout << BLU << "Form destructor called" << RST << std::endl;
}

Form&	Form::operator=(Form& copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

const std::string	Form::getName() const
{
	return (this->name);
}

bool 				Form::getSigned() const
{
	return (this->isSigned);
}

int			Form::getSignGrade() const
{
	return (this->signGrade);
}

int			Form::getExecGrade() const
{
	return (this->execGrade);
}


void	Form::beSigned(const Bureaucrat& bureaucrat)
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
		std::cout <<"his grade is too low!" << std::endl;
		throw GradeTooLowException();
	}
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("The form is already signed!");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << ", form. ";
	out << "Required grade to sign: " << form.getSignGrade() << ". ";
	out << "Required grade to execute: " << form.getExecGrade() << ".";
	out << std::endl;
	return (out);
}
