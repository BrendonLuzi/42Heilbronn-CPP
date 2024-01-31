/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:23:08 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 18:03:42 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP


#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float fx, const float fy);
		Point(const Point& copy);
		~Point();

		Point&	operator=(const Point& other);

		void		setx(Fixed const x);
		void		sety(Fixed const y);
		Fixed		getx(void) const;
		Fixed		gety(void) const;
};

#endif