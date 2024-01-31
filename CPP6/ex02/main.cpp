#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base	*generate(void)
{
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "Object of class A created" << std::endl;
		return new A();
	}
	else if (i == 1)
	{
		std::cout << "Object of class B created" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Object of class C created" << std::endl;
		return new C();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The pointer is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The pointer is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The pointer is of type C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The reference is of type A" << std::endl;
	}
	catch(...)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "The reference is of type B" << std::endl;
	}
	catch(...)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "The reference is of type C" << std::endl;
	}
	catch(...)
	{
	}
}

int	main(void)
{
	srand(time(NULL));

	Base	*base = generate();
	
	identify(base);
	
	identify(*base);
	
	delete base;
	
	return (0);
}