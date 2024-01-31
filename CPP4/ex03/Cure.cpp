//
// Created by Brendon Luzi on 10/16/23.
//

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& copy) : AMateria()
{
	*this = copy;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& copy)
{
	this->type = copy.type;
	return (*this);
}

Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
