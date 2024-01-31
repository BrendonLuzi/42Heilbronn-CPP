//
// Created by Brendon Luzi on 10/18/23.
//

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}


MateriaSource&	MateriaSource::operator=(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return (*this);
}


void		MateriaSource::learnMateria(AMateria* toLearn)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = toLearn->clone();
			std::cout << "The source learned the " << toLearn->getType() << " materia!!" << std::endl;
			return ;
		}
	}
	std::cout << "No space :(" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && !this->inventory[i]->getType().compare(type))
		{
			std::cout << "The source created a new " << type << " materia!!" << std::endl;
			return (this->inventory[i]->clone());
		}
	}
	std::cout << "The source doesn't know this one, sorry -___-" << std::endl;
	return (NULL);
}
