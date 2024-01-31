#ifndef CPP_SHRUBBERYCREATIONFORM_HPP
#define CPP_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RST "\e[0m"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm& copy);

	void		execute(const Bureaucrat& executor) const;
};


#endif
