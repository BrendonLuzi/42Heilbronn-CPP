//
// Created by Brendon Luzi on 10/16/23.
//

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat* cat = new Cat;
	Cat* anotherCat = new Cat;

	cat->eureka("catch mouse");
	cat->eureka("eat fish");

	anotherCat->eureka("miao");

	cat->getIdeas();
	anotherCat->getIdeas();

	*cat = *anotherCat;

	cat->getIdeas();

	delete cat;
	delete anotherCat;

	return 0;
}