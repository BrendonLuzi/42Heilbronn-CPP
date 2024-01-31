/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:50 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 18:04:27 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{	
}

Point::Point(const float fx, const float fy) : x(fx), y(fy)
{
}

Point::Point(const Point& copy) : x(copy.x), y(copy.y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point& other)
{
	this->setx(other.getx());
	this->sety(other.gety());
	return (*this);
}

void	Point::setx(Fixed const x)
{
	(Fixed)this->x = x;
}

void	Point::sety(Fixed const y)
{
	(Fixed)this->y = y;
}

Fixed	Point::getx(void) const
{
	return (x);
}

Fixed	Point::gety(void) const
{
	return (y);
}
