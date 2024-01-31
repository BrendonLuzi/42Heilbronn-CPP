#include "PmergeMe.hpp"
#include <sys/time.h>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char** input)
{
	this->fillVector(input);
	this->fillDeque(input);
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	this->vector = copy.vector;
	this->deque = copy.deque;
	return *this;
}

void PmergeMe::fillVector(char** input)
{
	while (*input)
	{
		this->vector.push_back(std::atoi(*input));
		input++;
	}
}

void PmergeMe::fillDeque(char** input)
{
	while (*input)
	{
		this->deque.push_back(std::atoi(*input));
		input++;
	}
}

void PmergeMe::MergeInsertVector()
{
	std::cout << "Vector:" << std::endl;
	std::cout << "  Before: " << this->vector << std::endl;

	struct timeval start, end;
	gettimeofday(&start, NULL);

	std::vector<std::pair<int, int> > pairVector = makePairVector();
	sortPairVector(pairVector);

	std::vector<int> mainChain = mainChainVector(pairVector);
	std::vector<int> subChain = subChainVector(pairVector);
	
	if (this->vector.size() % 2 == 1)
		subChain.push_back(this->vector[this->vector.size() - 1]);

	binaryInsertVector(mainChain, subChain);
	
	gettimeofday(&end, NULL);
	
	std::cout << "  After: " << mainChain << std::endl;
	std::cout << "  Time to process a range of " << this->vector.size() << " elements:\t";
	std::cout << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::makePairVector()
{
	std::vector<std::pair<int, int> > pairVector;
	for (std::vector<int>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
	{
		if (it + 1 != this->vector.end())
		{
			pairVector.push_back(std::pair<int, int>(*it, *(it + 1)));
			it++;
		}
	}

	return pairVector;
}

void PmergeMe::sortPairVector(std::vector<std::pair<int, int> >& pairVector)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}

	mergeSortVector(pairVector);
}

void PmergeMe::mergeSortVector(std::vector<std::pair<int, int> >& pairVector)
{
	if (pairVector.size() < 2)
		return ;

	std::vector<std::pair<int, int> > left;
	std::vector<std::pair<int, int> > right;

	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
	{
		if (it < pairVector.begin() + pairVector.size() / 2)
			left.push_back(*it);
		else
			right.push_back(*it);
	}

	mergeSortVector(left);
	mergeSortVector(right);

	pairVector.clear();
	mergeVector(pairVector, left, right);
}

void PmergeMe::mergeVector(std::vector<std::pair<int, int> >& pairVector, std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right)
{
	std::vector<std::pair<int, int> >::iterator itLeft = left.begin();
	std::vector<std::pair<int, int> >::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (itLeft->first < itRight->first)
			pairVector.push_back(*itLeft++);
		else
			pairVector.push_back(*itRight++);
	}
	while (itLeft != left.end())
		pairVector.push_back(*itLeft++);
	while (itRight != right.end())
		pairVector.push_back(*itRight++);
	
}

std::vector<int> PmergeMe::mainChainVector(std::vector<std::pair<int, int> > pairVector)
{
	std::vector<int> mainChain;
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
		mainChain.push_back(it->first);

	return mainChain;
}

std::vector<int> PmergeMe::subChainVector(std::vector<std::pair<int, int> > pairVector)
{
	std::vector<int> subChain;
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); it++)
		subChain.push_back(it->second);

	return subChain;
}

void PmergeMe::binaryInsertVector(std::vector<int>& mainChain, std::vector<int>& subChain)
{
	unsigned int JacobsthalNMinus2 = 0;
	unsigned int JacobsthalNMinus1 = 1;
	unsigned int Jacobsthal = JacobsthalNMinus1 + 2 * JacobsthalNMinus2;
	int pushed = 0;

	mainChain.insert(mainChain.begin(), subChain[0]);

	for (; JacobsthalNMinus1 < subChain.size(); Jacobsthal = JacobsthalNMinus1 + 2 * JacobsthalNMinus2)
	{
		for (unsigned int i = Jacobsthal; i > JacobsthalNMinus1; i--)
		{
			if (i > subChain.size())
				i = subChain.size();
			std::vector<int>::iterator find = binarySearchVector(mainChain, subChain[i - 1], 0, i + pushed++);
			mainChain.insert(find, subChain[i - 1]);
		}
		JacobsthalNMinus2 = JacobsthalNMinus1;
		JacobsthalNMinus1 = Jacobsthal;
	}
}

std::vector<int>::iterator PmergeMe::binarySearchVector(std::vector<int>& mainChain, int value, unsigned int low, unsigned int high)
{
	if (low == high)
		return mainChain.begin() + low;

	unsigned int mid = (low + high) / 2;

	if (value < mainChain[mid])
		return binarySearchVector(mainChain, value, low, mid);
	else if (value > mainChain[mid])
		return binarySearchVector(mainChain, value, mid + 1, high);
	else
		return mainChain.begin() + mid;
}

void PmergeMe::MergeInsertDeque()
{
	std::cout << "Deque:" << std::endl;
	std::cout << "  Before: " << this->deque << std::endl;
	struct timeval start, end;
	gettimeofday(&start, NULL);

	std::deque<std::pair<int, int> > pairDeque = makePairDeque();
	sortPairDeque(pairDeque);

	std::deque<int> mainChain = mainChainDeque(pairDeque);
	std::deque<int> subChain = subChainDeque(pairDeque);
	if (this->deque.size() % 2 == 1)
		subChain.push_back(this->deque[this->deque.size() - 1]);

	binaryInsertDeque(mainChain, subChain);

	gettimeofday(&end, NULL);

	std::cout << "  After: " << mainChain << std::endl;
	std::cout << "  Time to process a range of " << this->deque.size() << " elements:\t";
	std::cout << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << std::endl;
}

std::deque<std::pair<int, int> > PmergeMe::makePairDeque()
{
	std::deque<std::pair<int, int> > pairDeque;
	for (std::deque<int>::iterator it = this->deque.begin(); it != this->deque.end(); it++)
	{
		if (it + 1 != this->deque.end())
		{
			pairDeque.push_back(std::pair<int, int>(*it, *(it + 1)));
			it++;
		}
	}

	return pairDeque;
}

void PmergeMe::sortPairDeque(std::deque<std::pair<int, int> >& pairDeque)
{
	for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}

	mergeSortDeque(pairDeque);
}

void PmergeMe::mergeSortDeque(std::deque<std::pair<int, int> >& pairDeque)
{
	if (pairDeque.size() < 2)
		return ;

	std::deque<std::pair<int, int> > left;
	std::deque<std::pair<int, int> > right;

	for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); it++)
	{
		if (it < pairDeque.begin() + pairDeque.size() / 2)
			left.push_back(*it);
		else
			right.push_back(*it);
	}

	mergeSortDeque(left);
	mergeSortDeque(right);

	pairDeque.clear();
	mergeDeque(pairDeque, left, right);
}

void PmergeMe::mergeDeque(std::deque<std::pair<int, int> >& pairDeque, std::deque<std::pair<int, int> > left, std::deque<std::pair<int, int> > right)
{
	std::deque<std::pair<int, int> >::iterator itLeft = left.begin();
	std::deque<std::pair<int, int> >::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (itLeft->first < itRight->first)
			pairDeque.push_back(*itLeft++);
		else
			pairDeque.push_back(*itRight++);
	}
	while (itLeft != left.end())
		pairDeque.push_back(*itLeft++);
	while (itRight != right.end())
		pairDeque.push_back(*itRight++);
	
}

std::deque<int> PmergeMe::mainChainDeque(std::deque<std::pair<int, int> > pairDeque)
{
	std::deque<int> mainChain;
	for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); it++)
		mainChain.push_back(it->first);

	return mainChain;
}

std::deque<int> PmergeMe::subChainDeque(std::deque<std::pair<int, int> > pairDeque)
{
	std::deque<int> subChain;
	for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); it++)
		subChain.push_back(it->second);

	return subChain;
}

void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain, std::deque<int>& subChain)
{
	unsigned int JacobsthalNMinus2 = 0;
	unsigned int JacobsthalNMinus1 = 1;
	unsigned int Jacobsthal = JacobsthalNMinus1 + 2 * JacobsthalNMinus2;
	int pushed = 0;

	mainChain.insert(mainChain.begin(), subChain[0]);

	for (; JacobsthalNMinus1 < subChain.size(); Jacobsthal = JacobsthalNMinus1 + 2 * JacobsthalNMinus2)
	{
		for (unsigned int i = Jacobsthal; i > JacobsthalNMinus1; i--)
		{
			if (i > subChain.size())
				i = subChain.size();
			std::deque<int>::iterator find = binarySearchDeque(mainChain, subChain[i - 1], 0, i + pushed++);
			mainChain.insert(find, subChain[i - 1]);
		}
		JacobsthalNMinus2 = JacobsthalNMinus1;
		JacobsthalNMinus1 = Jacobsthal;
	}
}

std::deque<int>::iterator PmergeMe::binarySearchDeque(std::deque<int>& mainChain, int value, unsigned int low, unsigned int high)
{
	if (low == high)
		return mainChain.begin() + low;

	unsigned int mid = (low + high) / 2;

	if (value < mainChain[mid])
		return binarySearchDeque(mainChain, value, low, mid);
	else if (value > mainChain[mid])
		return binarySearchDeque(mainChain, value, mid + 1, high);
	else
		return mainChain.begin() + mid;
}
