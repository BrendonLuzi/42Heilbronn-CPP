//
// Created by Brendon Luzi on 10/16/23.
//

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& copy)
{
	*this = copy;
}

Character& Character::operator=(const Character &copy)
{
	this->name = copy.name;
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

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}


const std::string&	Character::getName() const
{
	return (this->name);
}

AMateria*	Character::getEquipment(int idx)
{
	if (idx >= 0 && idx < 4)
		return (this->inventory[idx]);
	return (NULL);
}

void	Character::equip(AMateria* m)
{
	std::cout << this->name << " is trying to equip something... ";
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			std::cout << this->name <<  " equipped the "<< m->getType() << " materia!" << std::endl;
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "No space :(" << std::endl;
}

void	Character::unequip(int idx)
{
	std::cout << this->name << " is trying to unequip something... ";
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		std::cout << this->name << " unequipped the " << this->inventory[idx]->getType() << " materia." << std::endl;
		this->inventory[idx] = NULL;
	}
	else
		std::cout << this->name << " can't unequip what doesn't exist .-." << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << this->name << " can't use what doesn't exist .-." << std::endl;
}
