//
// Created by Brendon Luzi on 10/16/23.
//

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor called!" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat& copy) : Animal()
{
	std::cout << "Cat copy constructor called!" << std::endl;
//	this->brain = new Brain;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& copy)
{
	this->type = copy.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*copy.brain);

	return (*this);
}

void	Cat::makeSound()	const
{
	std::cout << "Miao" << std::endl;
}

void	Cat::eureka(const std::string idea) const
{
	this->brain->addIdea(idea);
}

void	Cat::getIdeas() const
{
	this->brain->displayIdeas();
}