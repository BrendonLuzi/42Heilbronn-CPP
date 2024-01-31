/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:13:15 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 15:01:41 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream&out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	value = roundf((i * (power(2, fracBits))));
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf((f * (power(2, fracBits))));
}

Fixed::Fixed(const Fixed& copy) : value(copy.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (value);
}
		
void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	float f;
	
	f = value;
	f /= power(2, fracBits);
	
	return (f);
}

int		Fixed::toInt(void) const
{
	int i;
	
	i = value;
	i /= power(2, fracBits);
	
	return (i);
}

double power(double base, int exponent)
{
	double tmp;

	if (exponent == 0)
		return 1;

	tmp = power (base, exponent / 2);
	if ((exponent % 2) == 0) {
		return tmp * tmp;
	} else {
		if (exponent > 0)
			return base * tmp * tmp;
		else
			return (tmp * tmp) / base;
	}
}
