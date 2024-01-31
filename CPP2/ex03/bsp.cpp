/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:05:25 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 19:05:42 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	barCoord1, barCoord2, barCoord3(1), determinant;

	determinant = ((b.gety() - c.gety()) * (a.getx() - c.getx()))
		+ ((c.getx() - b.getx()) * (a.gety() - c.gety()));
	
	barCoord1 = (((b.gety() - c.gety()) * (point.getx() - c.getx()))
		+ ((c.getx() - b.getx()) * (point.gety() - c.gety()))) / determinant;

	barCoord2 = (((c.gety() - a.gety()) * (point.getx() - c.getx()))
		+ ((a.getx() - c.getx()) * (point.gety() - c.gety()))) / determinant;

	barCoord3 = barCoord3 - barCoord1 - barCoord2;

	if (barCoord1.toFloat() <= 0 || barCoord1.toFloat() >= 1)
		return (false);
	if (barCoord2.toFloat() <= 0 || barCoord2.toFloat() >= 1)
		return (false);
	if (barCoord3.toFloat() <= 0 || barCoord3.toFloat() >= 1)
		return (false);
	return (true);
}