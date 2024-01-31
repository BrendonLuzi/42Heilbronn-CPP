/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:13:03 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 14:11:49 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
	private:
		int	value;
		static const int fracBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		
		Fixed&	operator=(const Fixed& other);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif