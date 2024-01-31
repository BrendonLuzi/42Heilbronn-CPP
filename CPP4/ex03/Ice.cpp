//
// Created by Brendon Luzi on 10/16/23.
//

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& copy) : AMateria()
{
	*this = copy;
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(const Ice& copy)
{
	this->type = copy.type;
	return (*this);
}

Ice*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}
