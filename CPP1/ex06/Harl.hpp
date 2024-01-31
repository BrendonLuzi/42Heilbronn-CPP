/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:56:14 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/08 19:04:42 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP


#include <string>

class Harl
{
	private:
		void	debug (void);
		void	info (void);
		void	warning (void);
		void	error (void);
		
	public:
		void	complain(std::string level);
		void	filter(std::string level);
};

#endif