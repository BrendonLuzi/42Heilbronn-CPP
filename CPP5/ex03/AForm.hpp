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

class AForm
{
private:
	const std::string	name;
	const std::string	target;
	bool				isSigned;
	const int 			signGrade;
	const int 			execGrade;

public:
	AForm();
	AForm(const std::string name, const std::string target, const int signGrade, const int execGrade);
	AForm(AForm& copy);
	virtual ~AForm();

	AForm&	operator=(AForm& copy);

	const std::string	getName() const;
	const std::string	getTarget() const;
	bool				getSigned() const;
	int 				getSignGrade() const;
	int 				getExecGrade() const;
	void				setSigned(bool status);

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& executor) const = 0;

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

	class NotSignedException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
