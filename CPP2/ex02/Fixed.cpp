/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:13:15 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 17:15:12 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	value = roundf((i * (power(2, fracBits))));
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	value = roundf((f * (power(2, fracBits))));
}

Fixed::Fixed(const Fixed& copy) : value(copy.value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream&out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}
		
bool	Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}
		
bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}
		
bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}
		
bool	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}
		
bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}
		
		
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed fixed(this->toFloat() + other.toFloat());
	return (fixed);
}
		
Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed fixed(this->toFloat() - other.toFloat());
	return (fixed);
}
		
Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed fixed(this->toFloat() * other.toFloat());
	return (fixed);
}
		
Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed fixed(this->toFloat() / other.toFloat());
	return (fixed);
}

Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed old = *this;
	this->operator++();
	return (old);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed old = *this;
	this->operator--();
	return (old);
}

Fixed&	Fixed::min(Fixed& fixed, Fixed& other)
{
	if (fixed <= other)
		return (fixed);
	else
		return (other);
}

const Fixed&	Fixed::min(const Fixed& fixed, const Fixed& other)
{
	if ((Fixed)fixed <= (Fixed)other)
		return ((Fixed&)fixed);
	else
		return ((Fixed&)other);
}

Fixed&	Fixed::max(Fixed& fixed, Fixed& other)
{
	if (fixed >= other)
		return (fixed);
	else
		return (other);
}

const Fixed&	Fixed::max(const Fixed& fixed, const Fixed& other)
{
	if ((Fixed)fixed >= (Fixed)other)
		return ((Fixed&)fixed);
	else
		return ((Fixed&)other);
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
