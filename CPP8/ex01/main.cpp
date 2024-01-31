#include "Span.hpp"
#include <vector>
#include <cstdlib>

int main()
{
	Span span(2);

	span.addNumber(10);
	span.addNumber(2);

	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	try
	{
		span.addNumber(1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span span2(10);

	std::vector<int> vec;

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		vec.push_back(rand() % 100);

	span2.fillSet(vec.begin(), vec.end());

	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span2.longestSpan() << std::endl;

	Span span3(100000);

	span3.fillSet(0, 1000000000);

	std::cout << "Shortest span: " << span3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span3.longestSpan() << std::endl;

	return 0;
}