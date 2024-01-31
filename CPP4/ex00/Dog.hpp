//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP

#include "Animal.hpp"

class   Dog : public Animal
{
public:
	Dog();
	Dog(Dog& copy);
	~Dog();

	Dog& operator=(const Dog& copy);

	void	makeSound()	const;
};

#endif //CPP_DOG_HPP
