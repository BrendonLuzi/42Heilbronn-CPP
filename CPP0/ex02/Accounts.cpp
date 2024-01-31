
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}
	else
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (0);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

void	Account::_displayTimestamp(void)
{
	time_t time;
	std::time(&time);
	tm	tm_time = *std::localtime(&time);
	std::cout << "[";
	std::cout << 1900 + tm_time.tm_year;
	std::cout << std::setfill('0') << std::setw(2) << 1 + tm_time.tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << tm_time.tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << tm_time.tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm_time.tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm_time.tm_sec;
	std::cout << "] ";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "created" << std::endl;
}

Account::Account(void)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	_amount = 0;
	_totalAmount += 0;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}