#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename Type>
class Array
{
	private:
		Type			*array;
		unsigned int 	length;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &copy);
		~Array();

		Array &operator=(Array const &copy);
		Type &operator[](unsigned int i);
		const Type &operator[](unsigned int i) const;

		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif