#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename Type>
class MutantStack : public std::stack<Type>
{
public:
	MutantStack();
	MutantStack(MutantStack const& copy);
	~MutantStack();

	MutantStack& operator=(MutantStack const& copy);

	typedef typename std::stack<Type>::container_type::iterator iterator;
	typedef typename std::stack<Type>::container_type::const_iterator const_iterator;
	typedef typename std::stack<Type>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<Type>::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator cbegin() const;
	const_iterator cend() const;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
};
#include "MutantStack.tpp"

#endif
