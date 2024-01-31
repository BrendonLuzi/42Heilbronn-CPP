/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:19:42 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 17:02:45 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void)
{
	const std::string& typeRef = type;
	return (typeRef);
}

void Weapon::setType(std::string newType)
{
	type = newType;
}

Weapon::Weapon(std::string newType)
{
	type = newType;
}

Weapon::Weapon(void)
{
}
