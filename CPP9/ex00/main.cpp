#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	BitcoinExchange exchange;
	
	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	
	exchange.exchangeRequest(argv[1]);

	return (0);
}


// Input example:

// date | value
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1
// 2012-01-11 | 1
// 2019-01-11 | 1
// 2012-01-11 | -1
// 2001-10-10
// 2001-1	   | 5

// 2010-2-2-1 | 10
// 2001-42-42 | 1
// 2012-01-11 | 1000
// 2012-01-11 | 2147483648