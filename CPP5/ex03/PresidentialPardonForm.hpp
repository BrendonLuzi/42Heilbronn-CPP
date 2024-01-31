#ifndef CPP_PRESIDENTIALPARDONFORM_HPP
#define CPP_PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RST "\e[0m"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(PresidentialPardonForm& copy);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(PresidentialPardonForm& copy);

	void		execute(const Bureaucrat& executor) const;
};


#endif
