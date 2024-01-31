//
// Created by Brendon Luzi on 10/16/23.
//

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor called!" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog& copy) : Animal()
{
	std::cout << "Dog copy constructor called!" << std::endl;
//	this->brain = new Brain;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& copy)
{
	this->type = copy.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*copy.brain);

	return (*this);
}

void	Dog::makeSound()	const
{
	std::cout << "Bau" << std::endl;
}

void	Dog::eureka(const std::string idea) const
{
	this->brain->addIdea(idea);
}

void	Dog::getIdeas() const
{
	this->brain->displayIdeas();
}
