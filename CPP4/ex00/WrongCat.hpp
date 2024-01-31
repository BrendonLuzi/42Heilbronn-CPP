//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_WRONGCAT_HPP
#define CPP_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat& copy);
	~WrongCat();

	WrongCat& operator=(const WrongCat& copy);

	void	makeSound()	const;
};


#endif //CPP_WRONGCAT_HPP
