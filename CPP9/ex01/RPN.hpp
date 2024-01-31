#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <queue>

class RPN
{
private:
	std::queue<char> queue;

public:
	RPN();
	RPN(const RPN& copy);
	~RPN();

	RPN& operator=(const RPN& copy);

	void store_expression(std::string expression);
	void resolve_expression();

};

#endif
