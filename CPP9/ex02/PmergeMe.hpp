#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> vector;
	std::deque<int> deque;

public:
	PmergeMe();
	PmergeMe(char** input);
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& copy);

	void fillVector(char** input);
	void fillDeque(char** input);

	void MergeInsertVector();
	std::vector<std::pair<int, int> > makePairVector();
	void sortPairVector(std::vector<std::pair<int, int> >& pairVector);
	void mergeSortVector(std::vector<std::pair<int, int> >& pairVector);
	void mergeVector(std::vector<std::pair<int, int> >& pairVector, std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right);
	std::vector<int> mainChainVector(std::vector<std::pair<int, int> > pairVector);
	std::vector<int> subChainVector(std::vector<std::pair<int, int> > pairVector);
	void binaryInsertVector(std::vector<int>& mainChain, std::vector<int>& subChain);
	std::vector<int>::iterator binarySearchVector(std::vector<int>& mainChain, int value, unsigned int low, unsigned int high);

	void MergeInsertDeque();
	std::deque<std::pair<int, int> > makePairDeque();
	void sortPairDeque(std::deque<std::pair<int, int> >& pairDeque);
	void mergeSortDeque(std::deque<std::pair<int, int> >& pairDeque);
	void mergeDeque(std::deque<std::pair<int, int> >& pairDeque, std::deque<std::pair<int, int> > left, std::deque<std::pair<int, int> > right);
	std::deque<int> mainChainDeque(std::deque<std::pair<int, int> > pairDeque);
	std::deque<int> subChainDeque(std::deque<std::pair<int, int> > pairDeque);
	void binaryInsertDeque(std::deque<int>& mainChain, std::deque<int>& subChain);
	std::deque<int>::iterator binarySearchDeque(std::deque<int>& mainChain, int value, unsigned int low, unsigned int high);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector)
{
	for (typename std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); it++)
		out << *it << " ";

	return out;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deque)
{
	for (typename std::deque<T>::const_iterator it = deque.begin(); it != deque.end(); it++)
		out << *it << " ";

	return out;
};

#endif