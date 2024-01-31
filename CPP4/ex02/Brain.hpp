//
// Created by Brendon Luzi on 10/16/23.
//

#ifndef CPP_BRAIN_HPP
#define CPP_BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& copy);
	~Brain();

	Brain&	operator=(const Brain& copy);
	void	displayIdeas() const;
	void	addIdea(const std::string idea);
};


#endif //CPP_BRAIN_HPP
