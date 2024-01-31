//
// Created by Brendon Luzi on 10/16/23.
//

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor called!" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat& copy) : Animal()
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	this->type = copy.type;
	return (*this);
}

void	Cat::makeSound()	const
{
	std::cout << "Miao" << std::endl;
}
