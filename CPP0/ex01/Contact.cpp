/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:43 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/03 19:37:15 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdlib>

void	Contact::getField(std::string& field)
{
	while (1)
	{
		if (!std::getline(std::cin, field))
		{
			std::cout << "EOF!" << std::endl;
			exit (1);
		}
		if (field.empty())
			std::cout << "Cannot leave this field empty!" << std::endl;
		else
			break ;
		std::cout << "Try again:\t";
	}
}

void	Contact::generate(void)
{
	std::cout << "Input information" << std::endl;
	std::cout << "First name:\t";
	getField(firstName);
	std::cout << "Last name:\t";
	getField(lastName);
	std::cout << "Nickname:\t";
	getField(nickname);
	std::cout << "Phone number:\t";
	getField(phoneNumber);
	std::cout << "Darkest secret:\t";
	getField(darkSecret);
}

void	Contact::display(void)
{
	std::cout << "First name:\t" << firstName << std::endl;
	std::cout << "Last name:\t" << lastName << std::endl;
	std::cout << "Nickname:\t" << nickname << std::endl;
	std::cout << "Phone number:\t" << phoneNumber << std::endl;
	std::cout << "Darkest secret:\t" << darkSecret << std::endl;
}

void	Contact::preview(void)
{
	std::string	str;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (i == 0)
			str = firstName;
		else if (i == 1)
			str = lastName;
		else
			str = nickname;
		if (str.length() > 10)
		{
			str.resize(10);
			str[9] = '.';
		}
		std::cout << std::setw(10);
		std::cout << str;
		std::cout << '|';
		i++;
	}
}
