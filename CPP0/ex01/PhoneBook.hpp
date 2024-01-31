/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:00:42 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/03 19:21:06 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		class Contact	contact[8];
	
		int				getIndex();
	
	public:
		void			addContact(void);
		void			displayList(void);
};

#endif