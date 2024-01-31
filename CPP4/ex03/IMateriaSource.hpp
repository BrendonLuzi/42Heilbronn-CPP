//
// Created by Brendon Luzi on 10/18/23.
//

#ifndef CPP_IMATERIASOURCE_HPP
#define CPP_IMATERIASOURCE_HPP


#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //CPP_IMATERIASOURCE_HPP
