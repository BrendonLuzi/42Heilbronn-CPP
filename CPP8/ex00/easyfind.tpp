#include "easyfind.hpp"

template <typename Type>
typename Type::iterator	easyfind(Type& container, int toFind)
{
	typename Type::iterator searchResult;
	searchResult = std::find(container.begin(), container.end(), toFind);
	if (searchResult == container.end())
		throw std::exception();
	return (searchResult);
}