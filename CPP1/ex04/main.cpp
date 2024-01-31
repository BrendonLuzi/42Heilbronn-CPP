/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:50:18 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/08 16:48:30 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "You must insert 3 parameters to the function!" << std::endl;
		exit(1);
	}
	
	Replace file(argv[1]);
	file.replace(argv[2], argv[3]);
}