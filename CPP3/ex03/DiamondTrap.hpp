/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:22:25 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/16 10:48:51 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP


#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  virtual public FragTrap, virtual public ScavTrap
{
	private:
		std::string name;
		
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& copy);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap& copy);

		void		setDiamondName(const std::string name);
		std::string	getDiamondName(void) const;

		void		whoAmI();
		void		attack(const std::string& target);
};

#endif