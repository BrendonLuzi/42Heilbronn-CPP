#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("No name"), grade(150)
{
	std::cout << YEL << "Bureaucrat default constructor called" << RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout << YEL << "Bureaucrat parameterized constructor called" << RST << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name)
{
	std::cout << YEL << "Bureaucrat copy constructor called" << RST << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BLU << "Bureaucrat destructor called" << RST << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	this->grade = copy.grade;
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::promote()
{
	if (this->grade > 1)
	{
		std::cout << this->name << " has received a promotion to grade ";
		std::cout << --this->grade << "!" << std::endl;
	}
	else
		throw GradeTooHighException();
}

void	Bureaucrat::demote()
{
	if (this->grade < 150)
	{
		std::cout << this->name << " has been demoted to grade ";
		std::cout << ++this->grade << "." << std::endl;
	}
	else
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Exception thrown: ";
		std::cerr << e.what() << RST << std::endl;
	}

}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high! The highest possible grade is 1.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! The lowest possible grade is 150.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	out << std::endl;
	return (out);
}
