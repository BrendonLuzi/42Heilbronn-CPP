//
// Created by Brendon Luzi on 10/16/23.
//

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(Animal& copy)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal&	Animal::operator=(const Animal& copy)
{
	this->type = copy.type;
	return (*this);
}

void	Animal::makeSound()	const
{
	std::cout << "..." << std::endl;
}

std::string	Animal::getType()	const
{
	return (type);
}