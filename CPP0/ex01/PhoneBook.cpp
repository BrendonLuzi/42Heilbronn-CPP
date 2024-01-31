/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:44:49 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/03 19:45:18 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

static int	count = 0;

void	PhoneBook::addContact(void)
{
	class Contact	newContact;
	
	newContact.generate();
	contact[count % 8] = newContact;
	++count;
}

int	PhoneBook::getIndex(void)
{
	std::string	input;
	int			index;

	while (1)
	{
		try
		{
			std::cout << std::endl << "Input the index of the desired contact:\t";
			if (!std::getline(std::cin, input))
			{
				std::cerr << "EOF!" << std::endl;
				exit (1);
			}
			std::cout << std::endl;
			if (!input.empty())
			{
				index = std::atoi(input.c_str());
				if (!(index < 1 || index > 9 || index > count))
					break ;
				std::cout << "Invalid index!" << std::endl;
			}
			else
				std::cout << "Cannot leave this field empty!" << std::endl;
		}
		catch (...)
		{
			std::cout << "Invalid input" << std::endl;
		}
	}
	return (index);
}

void	PhoneBook::displayList(void)
{
	char		index;
	int			i = 0;

	if (!count)
	{
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}
	std::cout << std::setw(11) << "INDEX|";
	std::cout << std::setw(11) << "NAME|";
	std::cout << std::setw(11) << "SURNAME|";
	std::cout << std::setw(11) << "NICKNAME|" << std::endl << std::endl;
	while (i < 8 && i < count)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << '|';
		contact[i].preview();
		std::cout << std::endl;
		i++;
	}
	index = getIndex();
	contact[index - 1].display();
}
