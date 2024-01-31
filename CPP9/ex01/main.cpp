#include "RPN.hpp"

int main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
		return (1);
	}
	RPN rpn;
	try
	{
		rpn.store_expression(argv[1]);
		rpn.resolve_expression();
	}
	catch (std::exception& e)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
}