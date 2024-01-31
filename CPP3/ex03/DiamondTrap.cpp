/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:35:26 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/16 11:28:17 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap string constructor called!" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name")
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
	this->name = "NoName";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	*this = copy;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->name = copy.name;
	this->ClapTrap::name = copy.ClapTrap::name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name << ". ";
	std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::setDiamondName(const std::string name)
{
	this->name = name;
	ClapTrap::setName(name + "_clap_name");
}

std::string	DiamondTrap::getDiamondName() const
{
	return (this->name);
}
