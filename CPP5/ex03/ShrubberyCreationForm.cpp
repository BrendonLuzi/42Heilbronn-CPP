#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery creation", "No target", 145, 137)
{
	std::cout << YEL << "ShrubberyCreationForm default constructor called" << RST << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery creation", target, 145, 137)
{
	std::cout << YEL << "ShrubberyCreationForm paramaterized constructor called" << RST << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) :
	AForm("Shrubbery creation", copy.getTarget(), 145, 137)
{
	std::cout << YEL << "ShrubberyCreationForm copy constructor called" << RST << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BLU << "ShrubberyCreationForm destructor called" << RST << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy)
{
	this->setSigned(copy.getSigned());
	return (*this);
}

void		ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::ofstream out;
	out.open((this->getTarget() + "_shrubbery").c_str());
	out << "                                              .\n";
	out << "                                   .         ;\n";
	out << "      .              .              ;%     ;;\n";
	out << "        ,           ,                :;%  %;\n";
	out << "         :         ;                   :;%;'     .,\n";
	out << ",.        %;     %;            ;        %;'    ,;\n";
	out << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	out << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
	out << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
	out << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
	out << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
	out << "         `:%;.  :;bd%;          %;@%;'\n";
	out << "           `@%:.  :;%.         ;@@%;'\n";
	out << "             `@%.  `;@%.      ;@@%;\n";
	out << "               `@%%. `@%%    ;@@%;\n";
	out << "                 ;@%. :@%%  %@@%;\n";
	out << "                   %@bd%%%bd%%:;\n";
	out << "                     #@%%%%%:;;\n";
	out << "                     %@@%%%::;\n";
	out << "                     %@@@%(o);  . '\n";
	out << "                     %@@@o%;:(.,'\n";
	out << "                 `.. %@@@o%::;\n";
	out << "                    `)@@@o%::;\n";
	out << "                     %@@(o)::;\n";
	out << "                    .%@@@@%::;\n";
	out << "                    ;%@@@@%::;.\n";
	out << "                   ;%@@@@%%:;;;.\n";
	out << "               ...;%@@@@@%%:;;;;,..\n";
	out << "\n";
	out.close();
}

