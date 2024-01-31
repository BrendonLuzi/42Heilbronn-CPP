#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <cstdlib>

class Span
{
private:
	unsigned int		size;
	std::multiset<int>	int_set;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	~Span();

	Span&	operator=(const Span& copy);

	void	addNumber(int n);
	void	fillSet(int min, int max);

	template <typename Iterator>
	void	fillSet(Iterator begin, Iterator end)
	{
		if (this->int_set.size() >= this->size)
			throw Span::NoSpaceException();
		for (; begin != end; begin++)
			this->addNumber(*begin);
	}
	
	int		shortestSpan();
	int		longestSpan();

	class NoSpaceException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class NotEnoughElementsException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class RangeTooBigException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif