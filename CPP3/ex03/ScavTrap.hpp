/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:58:44 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 20:25:06 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(const ScavTrap& copy);
		virtual ~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& copy);

		void attack(const std::string& target);
		void guardGate();
};

#endif