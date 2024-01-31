#include "Span.hpp"
#include <climits>

Span::Span() : size(0)
{
}

Span::Span(unsigned int N) : size(N)
{
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& copy)
{
	if (this == &copy)
		return (*this);
	this->int_set = copy.int_set;
	this->size = copy.size;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->int_set.size() >= this->size)
		throw Span::NoSpaceException();
	this->int_set.insert(n);
}

void	Span::fillSet(int min, int max)
{
	if (this->int_set.size() >= this->size)
		throw Span::NoSpaceException();
	if ((double)(max - min) > RAND_MAX)
		throw Span::RangeTooBigException();
	
	srand(time(NULL));
	for (unsigned int i = this->int_set.size(); i < this->size; i++)
		this->int_set.insert(rand() % (max - min + 1) + min);
}

int		Span::shortestSpan()
{
	if (this->int_set.size() <= 1)
		throw Span::NotEnoughElementsException();

	int		shortest = INT_MAX;
	std::multiset<int>::iterator	start = this->int_set.begin();
	std::multiset<int>::iterator	end = this->int_set.end();
	std::multiset<int>::iterator	next = start;

	for (; start != end; start++)
	{
		next++;
		if (next != end)
		{
			int	tmp = *next - *start;
			if (tmp < shortest)
				shortest = tmp;
		}
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (this->int_set.size() <= 1)
		throw Span::NotEnoughElementsException();
	return (*(--this->int_set.end()) - *int_set.begin());
}

const char* Span::NoSpaceException::what() const throw()
{
	return ("No space left");
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return ("Not enough elements");
}

const char* Span::RangeTooBigException::what() const throw()
{
	return ("Range too big");
}