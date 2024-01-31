//
// Created by Brendon Luzi on 10/16/23.
//

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	this->type = copy.type;
	return (*this);
}

void	WrongAnimal::makeSound()	const
{
	std::cout << "..." << std::endl;
}

std::string	WrongAnimal::getType()	const
{
	return (type);
}