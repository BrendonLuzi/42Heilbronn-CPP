#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP


#include <string>
#include <iomanip>
#include "AForm.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RST "\e[0m"

class AForm;

class Bureaucrat
{
private:
	const std::string	name;
	int 				grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();

	Bureaucrat&		operator=(const Bureaucrat& copy);

	const std::string	getName() const;
	int 				getGrade() const;

	void				promote();
	void				demote();
	void				signForm(AForm& form) const;
	void				executeForm(const AForm& form) const;

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

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
