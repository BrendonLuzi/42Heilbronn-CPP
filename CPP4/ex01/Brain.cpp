//
// Created by Brendon Luzi on 10/16/23.
//

#include "Brain.hpp"
#include <iostream>


Brain::Brain()
{
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain&	Brain::operator=(const Brain& copy)
{
	std::copy(copy.ideas, copy.ideas + 100, this->ideas);
	return (*this);
}

void	Brain::displayIdeas() const
{
	int i = 0;

	std::cout << "Ideas:" << std::endl;
	while (i < 100 && !this->ideas[i].empty())
		std::cout << "\t" << ideas[i++] << std::endl;
	std::cout << std::endl;
}

void	Brain::addIdea(const std::string idea)
{
	int i = 0;

	while (i < 100 && !this->ideas[i].empty())
		i++;
	if (i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "No more space for ideas! :(" << std::endl;
}