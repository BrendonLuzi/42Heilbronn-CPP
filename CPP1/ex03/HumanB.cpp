/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:12 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 17:44:51 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack()
{
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon->getType() << std::endl;
}

HumanB::HumanB (std::string newName) : name(newName)
{
}

void HumanB::setWeapon (Weapon& newWeapon)
{
	weapon = &newWeapon;
}