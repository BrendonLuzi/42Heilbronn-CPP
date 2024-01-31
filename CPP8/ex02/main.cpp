#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mutant_stack;

	mutant_stack.push(1);
	mutant_stack.push(4);
	mutant_stack.push(7);
	mutant_stack.push(2);

	std::cout << "Size: " << mutant_stack.size() << std::endl;
	std::cout << "Top: " << mutant_stack.top() << std::endl;
	std::cout << "MutantStack: ";
	for (MutantStack<int>::iterator it = mutant_stack.begin(); it != mutant_stack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	

	std::cout << std::endl;
	std::cout << "Pop top element" << std::endl;
	mutant_stack.pop();

	std::cout << "Size: " << mutant_stack.size() << std::endl;
	std::cout << "Top: " << mutant_stack.top() << std::endl;
	std::cout << "MutantStack: ";
	for (MutantStack<int>::iterator it = mutant_stack.begin(); it != mutant_stack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Creating a const mutant_stack and using const iterators" << std::endl;
	const MutantStack<int> const_mutant_stack(mutant_stack);
	for (MutantStack<int>::const_iterator it = const_mutant_stack.cbegin(); it != const_mutant_stack.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Using reverse iterators and const reverse iterators" << std::endl;
	for (MutantStack<int>::reverse_iterator it = mutant_stack.rbegin(); it != mutant_stack.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (MutantStack<int>::const_reverse_iterator it = const_mutant_stack.crbegin(); it != const_mutant_stack.crend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Create a stack from the mutant_stack" << std::endl;
	std::stack<int> stack(mutant_stack);

	std::cout << "Size: " << stack.size() << std::endl;
	std::cout << "Top: " << stack.top() << std::endl;
	std::cout << "Stack: ";
	while (!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}

	std::cout << std::endl;
}