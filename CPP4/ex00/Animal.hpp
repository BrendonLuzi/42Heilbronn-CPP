//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_ANIMAL_HPP
#define CPP_ANIMAL_HPP

#include <string>

class   Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(Animal& copy);
	virtual ~Animal();

	Animal& operator=(const Animal& copy);

	std::string		getType() const;
	virtual void	makeSound()	const;
};

#endif //CPP_ANIMAL_HPP
