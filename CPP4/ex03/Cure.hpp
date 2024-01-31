//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_CURE_HPP
#define CPP_CURE_HPP


#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& copy);
	~Cure();

	Cure&	operator=(const Cure& copy);

	Cure*	clone() const;
	void	use(ICharacter& target);
};


#endif //CPP_CURE_HPP
