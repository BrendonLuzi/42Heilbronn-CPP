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

#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
	DiamondTrap cp1("Dio");
	DiamondTrap cp(cp1);
	std::string	target = "Cristo";

	std::cout << std::endl;
	std::cout << "Name: " << cp.getDiamondName();
	std::cout << ". Hp: " << cp.getHitPoints();
	std::cout << ". Energy points: " << cp.getEnergyPoints();
	std::cout << ". Attack: " << cp.getAttackDamage() << std::endl;
	std::cout << std::endl;

	cp.whoAmI();
	cp.attack(target);
	cp.beRepaired(10);
	cp.takeDamage(50);
	cp.attack(target);
	cp.takeDamage(50);
	cp.beRepaired(10);
	cp.attack(target);
	cp.guardGate();
	cp.highFivesGuys();

	std::cout << std::endl;
	std::cout << "Name : " << cp.getDiamondName();
	std::cout << ". Hp : " << cp.getHitPoints();
	std::cout << ". Energy points : " << cp.getEnergyPoints();
	std::cout << ". Attack : " << cp.getAttackDamage() << std::endl;
	std::cout << std::endl;
	return 0;
}