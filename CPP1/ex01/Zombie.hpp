/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:50:15 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 14:37:48 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string	name;
	
public:
	void		announce(void);
	void		assignName(std::string zName);

	Zombie(std::string zName);
	Zombie(void);
	~Zombie();
};

#endif