//
// Created by Brendon Luzi on 10/16/23.
//

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called!" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat& copy) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	this->type = copy.type;
	return (*this);
}

void	WrongCat::makeSound()	const
{
	std::cout << "Miao" << std::endl;
}
