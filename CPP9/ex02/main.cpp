#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./a.out [int] [int] ..." << std::endl;
		return 1;
	}

	if (argc == 2)
	{
		std::cout << "Come on, one alone is always sorted! 0 us, magic..." << std::endl;
		return 1;
	}

	PmergeMe pm(argv + 1);
	
	pm.MergeInsertVector();
	pm.MergeInsertDeque();

	return 0;
}