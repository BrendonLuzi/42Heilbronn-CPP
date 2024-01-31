/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:22:35 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 17:44:15 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	
	public:
		void		attack();
		void		setWeapon(Weapon& newWeapon);
		HumanB(std::string newName);
};

#endif