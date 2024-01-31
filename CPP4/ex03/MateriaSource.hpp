//
// Created by Brendon Luzi on 10/18/23.
//

#ifndef CPP_MATERIASOURCE_HPP
#define CPP_MATERIASOURCE_HPP


#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
protected:
	AMateria*	inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& copy);

	void		learnMateria(AMateria* toLearn);
	AMateria*	createMateria(const std::string& type);
};


#endif //CPP_MATERIASOURCE_HPP
