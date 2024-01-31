/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:12 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 17:27:10 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void HumanA::attack()
{
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::HumanA (std::string newName, Weapon& newWeapon) : name(newName) , weapon(newWeapon)
{
}