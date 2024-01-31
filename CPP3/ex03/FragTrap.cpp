/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:34:25 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 20:51:28 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap()
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage= copy.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (getHitPoints() < 1 || getEnergyPoints() < 1)
	{
		std::cout << "FragTrap " << getName();
		std::cout << " doesn't have enough energy or hit points to perform the action!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName();
	std::cout << " says, \"Gimme five bro!\"" << std::endl;
}
