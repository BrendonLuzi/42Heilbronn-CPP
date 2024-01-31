/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:19:17 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 19:41:18 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <string>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& copy);

		void		setName(const std::string name);
		void		setHitPoints(const int hitPoints);
		void		setEnergyPoints(const int energyPoints);
		void		setAttackDamage(const int attackDamage);
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif