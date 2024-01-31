//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_WRONGANIMAL_HPP
#define CPP_WRONGANIMAL_HPP

#include <string>

class   WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal& copy);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& copy);

	std::string		getType() const;
	void	makeSound()	const;
};

#endif //CPP_WRONGANIMAL_HPP
