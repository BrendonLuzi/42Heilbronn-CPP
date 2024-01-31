//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
private:
	Brain*	brain;
public:
	Cat();
	Cat(Cat& copy);
	~Cat();

	Cat& operator=(const Cat& copy);

	void	makeSound()	const;
	void	eureka(const std::string idea) const;
	void	getIdeas() const;
};


#endif //CPP_CAT_HPP
