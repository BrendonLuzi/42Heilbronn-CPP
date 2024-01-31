/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:34:38 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 20:37:40 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap& copy);
		virtual ~FragTrap();

		FragTrap&	operator=(const FragTrap& copy);

		void highFivesGuys(void);
};

#endif