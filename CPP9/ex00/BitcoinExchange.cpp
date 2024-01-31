#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
	storeDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		this->database = copy.database;
	return (*this);
}

bool isValidDate(std::string line)
{
	if (line.find("|"))
		line = line.substr(0, line.find_first_not_of("0123456789-"));
	else
		line = line.substr(0, line.find_first_of(','));
	if (line.find_first_not_of("0123456789-") != std::string::npos)
		return (false);
	if (line.find_first_of('-') != 4 || line.find_last_of('-') != 7)
		return (false);
	if (std::count(line.begin(), line.end(), '-') != 2)
		return (false);
	return (true);
}

int	get_date(std::string line)
{
	int year;
	int month;
	int day;

	if (isValidDate(line) == false)
		throw BitcoinExchange::BadDateException();

	year = std::atoi(line.substr(0, line.find_first_of('-')).c_str());
	month = std::atoi(line.substr(line.find_first_of('-') + 1, line.find_last_of('-')).c_str());
	day = std::atoi(line.substr(line.find_last_of('-') + 1, line.find_first_of(',')).c_str());
	
	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw BitcoinExchange::BadDateException();

	return (year * 10000 + month * 100 + day);
}

void BitcoinExchange::storeDatabase(std::string filename)
{
	std::ifstream input;
	std::string line;

	input.open(filename.c_str());
	if (!input.is_open())
	{
		std::cout << "Error: File not found." << std::endl;
		return ;
	}
	
	std::getline(input, line);
	while (std::getline(input, line))
	{
		int date = get_date(line);
		double price = std::strtod(line.substr(line.find_last_of(',') + 1).c_str(), NULL);
		this->database.insert(std::pair<int, double>(date, price));
	}
	input.close();
}

void BitcoinExchange::exchangeItem(std::string line)
{
		int date = get_date(line);

		double amount = std::strtod(line.substr(line.find_last_of('|') + 1).c_str(), NULL);
		if (amount < 0 || amount > 1000)
			throw BitcoinExchange::AmountException();

		std::map<int, double>::iterator it = this->database.upper_bound(date);
		if (it == this->database.begin())
			throw BitcoinExchange::TooEarlyException();
		if (it->first != date)
			it--;

		std::cout << line.substr(0, line.find_first_of('|'));
		std::cout << "=> " << amount << " = "<< amount * it->second << std::endl;
}

void BitcoinExchange::exchangeRequest(std::string filename)
{
	std::ifstream input;
	std::string line;

	input.open(filename.c_str());
	if (!input.is_open())
	{
		std::cout << "Error: File not found." << std::endl;
		return ;
	}

	std::getline(input, line);
	while (std::getline(input, line))
	{
		try
		{
			if (line.find_first_of('|') == std::string::npos || line.find_first_of("0123456789", line.find_first_of('|')) == std::string::npos)
				throw BitcoinExchange::BadInputException();
			exchangeItem(line);
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: " << e.what();
			if (dynamic_cast<const BitcoinExchange::BadInputException*>(&e))
				std::cout << " => \"" << line << "\"";
			std::cout << std::endl;
		}
	}
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return ("Bad input.");
}

const char* BitcoinExchange::BadDateException::what() const throw()
{
	return ("Invalid date.");
}

const char* BitcoinExchange::AmountException::what() const throw()
{
	return ("Invalid amount, must be between 0 and 1000.");
}

const char* BitcoinExchange::TooEarlyException::what() const throw()
{
	return ("Too early to find an occurrence in the database.");
}