#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN&copy) : queue(copy.queue)
{
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& copy)
{
	queue = copy.queue;
	return (*this);
}

void RPN::store_expression(std::string expression)
{
	for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
		if (*it != ' ')
			queue.push(*it);
}

bool	is_operand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void RPN::resolve_expression()
{
	std::stack<double> stack;

	while (!queue.empty())
	{
		if (isdigit(queue.front()))
		{
			stack.push(static_cast<double>(queue.front() - '0'));
			queue.pop();
		}
		else if (is_operand(queue.front()))
		{
			if (stack.size() < 2)
				throw std::exception();
			double	first = stack.top();
			stack.pop();
			double	second = stack.top();
			stack.pop();
			if (queue.front() == '+')
				stack.push(second + first);
			else if (queue.front() == '-')
				stack.push(second - first);
			else if (queue.front() == '*')
				stack.push(second * first);
			else if (queue.front() == '/')
				stack.push(second / first);
			queue.pop();
		}
		else
			throw std::exception();
	}
	if (stack.size() != 1)
		throw std::exception();
	std::cout << stack.top() << std::endl;
}
