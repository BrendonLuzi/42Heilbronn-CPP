//
// Created by Brendon Luzi on 10/16/23.
//

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called!" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog& copy) : Animal()
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	this->type = copy.type;
	return (*this);
}

void	Dog::makeSound()	const
{
	std::cout << "Bau" << std::endl;
}
