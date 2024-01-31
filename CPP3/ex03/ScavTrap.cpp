/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:58:15 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 20:26:23 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called!" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage= copy.attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() < 1 || getEnergyPoints() < 1)
	{
		std::cout << "ScavTrap " << getName();
		std::cout << " doesn't have enough energy or hit points to perform the action!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << getName();
	std::cout << " attacks " << target;
	std::cout << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}


void ScavTrap::guardGate()
{
	if (getHitPoints() < 1 || getEnergyPoints() < 1)
	{
		std::cout << "ScavTrap " << getName();
		std::cout << " doesn't have enough energy or hit points to perform the action!" << std::endl;
		return ;
	}
	std::cout << "Beware, ScavTrap " << getName();
	std::cout << " is now in Gate keeper mode!" << std::endl;
}
