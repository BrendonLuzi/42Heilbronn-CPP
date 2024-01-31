//
// Created by Brendon Luzi on 10/18/23.
//

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	AMateria* tmp;
	//	Materia source creation
	IMateriaSource* source = new MateriaSource();
	tmp = new Ice();
	source->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	source->learnMateria(tmp);
	delete tmp;

	std::cout << std::endl;
	//	Character creation and equipment of materias
	ICharacter* character = new Character("Tony Pizza");
	character->equip(source->createMateria("ice"));
	character->equip(source->createMateria("cure"));
	character->equip(source->createMateria("ice"));
	character->equip(source->createMateria("cure"));

	std::cout << std::endl;
	//	Check for incorrect usage of equipment or materia creation
	tmp = source->createMateria("fire");
	tmp = source->createMateria("ice");
	character->equip(tmp);
	delete	tmp;

	std::cout << std::endl;
	//	Use materias
	ICharacter* enemy = new Character("Johnny Peperoni");
	character->use(0, *enemy);
	character->use(1, *enemy);
	character->use(2, *enemy);

	std::cout << std::endl;

	//	Unequip materias and consequences
	tmp = ((Character *)character)->getEquipment(2);
	character->unequip(2);
	character->use(0, *enemy);
	character->use(1, *enemy);
	character->use(2, *enemy);

	//	Freeing of all allocated resources
	delete character;
	delete enemy;
	delete source;
	delete tmp;
	return 0;
}
