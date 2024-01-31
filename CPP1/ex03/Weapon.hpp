/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:16:06 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 17:01:44 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string	type;
	
	public:
		const std::string& getType(void);
		void setType(std::string newType);
		Weapon(std::string newType);
		Weapon(void);
};

#endif