#include "Array.hpp"

template <typename Type>
Array<Type>::Array() : array(NULL), length(0)
{
}

template <typename Type>
Array<Type>::Array(unsigned int n) : array(new Type[n]), length(n)
{
}

template <typename Type>
Array<Type>::Array(Array const &copy) : array(NULL), length(0)
{
	*this = copy;
}

template <typename Type>
Array<Type>::~Array()
{
	if (array != NULL)
		delete[] array;
}

template <typename Type>
Array<Type> &Array<Type>::operator=(Array const &copy)
{
	if (this != &copy)
	{
		if (array != NULL)
			delete[] array;
		length = copy.length;
		array = new Type[length];
		for (unsigned int i = 0; i < length; i++)
			array[i] = copy.array[i];
	}
	return (*this);
}

template <typename Type>
Type &Array<Type>::operator[](unsigned int i)
{
	if (this->array == NULL)
		throw NoArrayException();
	if (i >= length)
		throw OutOfBoundsException();
	return (array[i]);
}

template <typename Type>
const Type &Array<Type>::operator[](unsigned int i) const
{
	if (this->array == NULL)
		throw NoArrayException();
	if (i >= length)
		throw OutOfBoundsException();
	return (array[i]);
}

template <typename Type>
unsigned int Array<Type>::size() const
{
	return (length);
}

template <typename Type>
const char *Array<Type>::OutOfBoundsException::what() const throw()
{
	return ("Out of bounds");
}

template <typename Type>
const char *Array<Type>::NoArrayException::what() const throw()
{
	return ("No array");
}