//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_CHARACTER_HPP
#define CPP_CHARACTER_HPP


#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string		name;
	AMateria*		inventory[4];
public:
	Character();
	Character(const std::string name);
	Character(const Character& copy);
	~Character();

	Character&	operator=(const Character& copy);

	const std::string&	getName() const;
	AMateria*			getEquipment(int idx);
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};


#endif //CPP_CHARACTER_HPP
