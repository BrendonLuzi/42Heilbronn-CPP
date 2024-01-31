//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal
{
private:
	Brain*	brain;
public:
	Dog();
	Dog(Dog& copy);
	~Dog();

	Dog& operator=(const Dog& copy);

	void	makeSound()	const;
	void	eureka(const std::string idea) const;
	void	getIdeas() const;
};

#endif //CPP_DOG_HPP
