/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:55:05 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 14:33:39 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::assignName(std::string zName)
{
	name = zName;
}

Zombie::Zombie(std::string zName)
{
	name = zName;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << name << "'s destructor called" << std::endl;
}
