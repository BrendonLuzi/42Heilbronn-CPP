//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_ICE_HPP
#define CPP_ICE_HPP


#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& copy);
	~Ice();

	Ice&	operator=(const Ice& copy);

	Ice*	clone() const;
	void	use(ICharacter& target);
};


#endif //CPP_ICE_HPP
