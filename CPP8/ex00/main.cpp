#include "easyfind.hpp"
#include <vector>
#include <set>
#include <iostream>

int main()
{
	std::vector<int>	vec;
	for (int i = 0; i < 100; i++)
		vec.push_back(i);
	std::set<int>	set (vec.begin(), vec.end());

	try
	{
		std::cout << *easyfind(vec, 42) << std::endl;
		std::cout << *easyfind(set, 42) << std::endl;
		std::cout << *easyfind(vec, 100) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Not found!" << std::endl;
	}
	
}
