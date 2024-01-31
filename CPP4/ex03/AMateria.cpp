//
// Created by Brendon Luzi on 10/16/23.
//

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string& type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& copy)
{
	this->type = copy.type;
	return (*this);
}

const std::string&	AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Do nothing at " << target.getName() << std::endl;
}
