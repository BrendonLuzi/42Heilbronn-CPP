/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:57:01 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/08 19:10:57 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug (void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info (void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning (void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout <<  "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error (void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain (std::string level)
{
	void (Harl::* funcs[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	std::string levelArray[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	int i = 0;
	while ((levelArray[i]).compare(level) && i < 4)
		i++;
	if (i < 4)
		(this->*funcs[i])();
}

void	Harl::filter (std::string level)
{
	void (Harl::* funcs[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	std::string levelArray[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	int i = 0;
	while ((levelArray[i]).compare(level) && i < 4)
		i++;
	
	switch (i)
	{
		case 0:
			(this->*funcs[0])();
			//fall through
		case 1:
			(this->*funcs[1])();
			//fall through
		case 2:
			(this->*funcs[2])();
			//fall through
		case 3:
			(this->*funcs[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
