//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"

class   Cat : public Animal
{
public:
	Cat();
	Cat(Cat& copy);
	~Cat();

	Cat& operator=(const Cat& copy);

	void	makeSound()	const;
};


#endif //CPP_CAT_HPP
