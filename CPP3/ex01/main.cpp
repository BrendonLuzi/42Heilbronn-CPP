/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:50:18 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 20:27:06 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	ScavTrap cp("Johnny Peperoni");
	std::string	target = "Micheal Obama";


	std::cout << std::endl;
	std::cout << "Name: " << cp.getName();
	std::cout << ". Hp: " << cp.getHitPoints();
	std::cout << ". Energy points: " << cp.getEnergyPoints();
	std::cout << ". Attack: " << cp.getAttackDamage() << std::endl;
	std::cout << std::endl;

	cp.attack(target);
	cp.beRepaired(1);
	cp.takeDamage(10);
	cp.attack(target);
	cp.takeDamage(1);
	cp.beRepaired(1);
	cp.attack(target);
	cp.guardGate();

	std::cout << std::endl;
	std::cout << "Name : " << cp.getName();
	std::cout << ". Hp : " << cp.getHitPoints();
	std::cout << ". Energy points : " << cp.getEnergyPoints();
	std::cout << ". Attack : " << cp.getAttackDamage() << std::endl;
	std::cout << std::endl;
	return 0;
}