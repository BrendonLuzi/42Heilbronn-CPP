#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<int, double> database;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& copy);

	void storeDatabase(std::string filename);
	void exchangeRequest(std::string filename);
	void exchangeItem(std::string line);

	class BadInputException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class BadDateException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class AmountException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class TooEarlyException : public std::exception
	{
		virtual const char* what() const throw();
	};

};

#endif