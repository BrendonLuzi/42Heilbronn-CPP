/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:04:41 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/03 18:33:13 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	class PhoneBook	phonebook;
	std::string		input;
	
	while (1)
	{

		std::cout << std::endl << "Select a command between ADD, SEARCH and EXIT" << std::endl;
		if (!std::getline(std::cin, input))
			return (std::cerr << "EOF!" << std::endl, 1);
		std::cout << std::endl;
		if (!input.compare("ADD"))
			phonebook.addContact();
		else if (!input.compare("SEARCH"))
			phonebook.displayList();
		else if (!input.compare("EXIT"))
			break ;
		else
			std::cout << "Invalid input!" << std::endl;
	}
}