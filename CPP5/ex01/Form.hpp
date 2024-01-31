#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RST "\e[0m"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int 			signGrade;
	const int 			execGrade;

public:
	Form();
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(Form& copy);
	~Form();

	Form&	operator=(Form& copy);

	const std::string	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void	beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
