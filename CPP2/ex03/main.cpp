/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:50:18 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/09 19:10:26 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point a(0, 0), b(0, 5), c(5, 0), p1(2, 2), p2(5, 5), p3(0.01, 2), p4(0, 0);


	std::cout << "The first point [" << p1.getx() << ", " << p1.gety() << "] is ";
	if (bsp(a, b, c, p1))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;

	std::cout << "The second point [" << p2.getx() << ", " << p2.gety() << "] is ";
	if (bsp(a, b, c, p2))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;

	std::cout << "The third point [" << p3.getx() << ", " << p3.gety() << "] is ";
	if (bsp(a, b, c, p3))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;

	std::cout << "The fourth point [" << p4.getx() << ", " << p4.gety() << "] is ";
	if (bsp(a, b, c, p4))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;
}