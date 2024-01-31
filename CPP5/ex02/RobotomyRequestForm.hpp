#ifndef CPP_ROBOTOMYREQUESTFORM_HPP
#define CPP_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RST "\e[0m"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(RobotomyRequestForm& copy);

	void		execute(const Bureaucrat& executor) const;
};


#endif
