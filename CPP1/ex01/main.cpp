/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:50:18 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/07 14:57:52 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>


Zombie* zombieHorde(int N, std::string name);

int	main()
{
	Zombie *zombie;
	std::srand(time(NULL));
	int N = std::rand() % 10 + 1;

	zombie = zombieHorde(N, "Pipipupu");
	for (int i = 0; i < N; i++)
	{
		std::cout << i << '.';
		zombie[i].announce();
	}
	delete[] zombie;
}