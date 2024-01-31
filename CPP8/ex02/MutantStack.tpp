#include "MutantStack.hpp"

template <typename Type>
MutantStack<Type>::MutantStack() : std::stack<Type>()
{
};

template <typename Type>
MutantStack<Type>::MutantStack(MutantStack const& copy) : std::stack<Type>(copy)
{
};

template <typename Type>
MutantStack<Type>::~MutantStack()
{
};

template <typename Type>
MutantStack<Type>& MutantStack<Type>::operator=(MutantStack const& copy)
{
	if (this != &copy)
		std::stack<Type>::operator=(copy);
	return (*this);
};

template <typename Type>
typename MutantStack<Type>::iterator MutantStack<Type>::begin()
{
	return (std::stack<Type>::c.begin());
};

template <typename Type>
typename MutantStack<Type>::iterator MutantStack<Type>::end()
{
	return (std::stack<Type>::c.end());
};

template <typename Type>
typename MutantStack<Type>::reverse_iterator MutantStack<Type>::rbegin()
{
	return (std::stack<Type>::c.rbegin());
};

template <typename Type>
typename MutantStack<Type>::reverse_iterator MutantStack<Type>::rend()
{
	return (std::stack<Type>::c.rend());
};

template <typename Type>
typename MutantStack<Type>::const_iterator MutantStack<Type>::cbegin() const
{
	return (std::stack<Type>::c.begin());
};

template <typename Type>
typename MutantStack<Type>::const_iterator MutantStack<Type>::cend() const
{
	return (std::stack<Type>::c.end());
};

template <typename Type>
typename MutantStack<Type>::const_reverse_iterator MutantStack<Type>::crbegin() const
{
	return (std::stack<Type>::c.rbegin());
};

template <typename Type>
typename MutantStack<Type>::const_reverse_iterator MutantStack<Type>::crend() const
{
	return (std::stack<Type>::c.rend());
};
