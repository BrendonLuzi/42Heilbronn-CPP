/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:50:15 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/06 19:30:36 by bluzi            ###   ########.fr       */
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

	Zombie(std::string zName);
	~Zombie();
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif