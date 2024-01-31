/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:19:05 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 19:49:40 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string name)
	: hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap string constructor called!" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap()
	: name ("NoName"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy constructor called!" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage= copy.attackDamage;
	return (*this);
}

void		ClapTrap::setName(const std::string name)
{
	this->name = name;
}

void		ClapTrap::setHitPoints(const int hitPoints)
{
	this->hitPoints = hitPoints;
}

void		ClapTrap::setEnergyPoints(const int energyPoints)
{
	this->energyPoints = energyPoints;
}

void		ClapTrap::setAttackDamage(const int attackDamage)
{
	this->attackDamage = attackDamage;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

int			ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

int			ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

int			ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}


void		ClapTrap::attack(const std::string& target)
{
	if (hitPoints < 1 || energyPoints < 1)
	{
		std::cout << "ClapTrap " << name;
		std::cout << " doesn't have enough energy or hit points to perform the action!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name;
	std::cout << " attacks " << target;
	std::cout << " causing " << attackDamage << " points of damage!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	std::cout << "ClapTrap " << name;
	std::cout << " receives " << amount << " points of damage!" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints < 1 || hitPoints < 1)
	{
		std::cout << "ClapTrap " << name;
		std::cout << " doesn't have enough energy or hit points to perform the action!" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name;
	std::cout << " recovers " << amount << " hit points!" << std::endl;
}
