//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_AMATERIA_HPP
#define CPP_AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria
{
protected:
	std::string	type;
public:
	AMateria(const std::string& type);
	AMateria();
	AMateria(const AMateria& copy);
	virtual ~AMateria();

	AMateria&	operator=(const AMateria& copy);

	const std::string&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void 		use(ICharacter& target);
};


#endif //CPP_AMATERIA_HPP
