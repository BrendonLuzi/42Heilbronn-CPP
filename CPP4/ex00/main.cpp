//
// Created by Brendon Luzi on 10/16/23.
//

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Animal* undefined = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	cat->makeSound();
	dog->makeSound();
	undefined->makeSound();

	delete undefined;
	delete dog;
	delete cat;

	const WrongAnimal* wrongcat = new WrongCat();
	wrongcat->makeSound();
	delete wrongcat;

	return 0;
}