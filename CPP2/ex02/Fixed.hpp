/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:13:03 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 15:39:46 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		static const int fracBits = 8;
	
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& copy);
		~Fixed();
		
		Fixed&			operator=(const Fixed& other);
		
		bool			operator>(const Fixed& other) const;
		bool			operator<(const Fixed& other) const;
		bool			operator>=(const Fixed& other) const;
		bool			operator<=(const Fixed& other) const;
		bool			operator==(const Fixed& other) const;
		bool			operator!=(const Fixed& other) const;
		
		Fixed			operator+(const Fixed& other) const;
		Fixed			operator-(const Fixed& other) const;
		Fixed			operator*(const Fixed& other) const;
		Fixed			operator/(const Fixed& other) const;
		
		Fixed&			operator++(void);
		Fixed			operator++(int);
		Fixed&			operator--(void);
		Fixed			operator--(int);
		
		static Fixed&	min(Fixed& fixed, Fixed& other);
		const static Fixed&	min(const Fixed& fixed, const Fixed& other);
		static Fixed&	max(Fixed& fixed, Fixed& other);
		const static Fixed&	max(const Fixed& fixed, const Fixed& other);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

double			power(double base, int exponent);
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif