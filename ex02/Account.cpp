#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_accountIndex = _nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm *local_time = std::localtime(&now);

	std::cout << "[" << (1900 + local_time->tm_year);
	if (1 + local_time->tm_mon < 10)
		std::cout << "0";
	std::cout << 1 + local_time->tm_mon;
	if (local_time->tm_mday < 10)
		std::cout << "0";
	std::cout << local_time->tm_mday << "_";
	if (local_time->tm_hour < 10)
		std::cout << "0";
	std::cout << local_time->tm_hour;
	if (local_time->tm_min < 10)
		std::cout << "0";
	std::cout << local_time->tm_min;
	if (local_time->tm_sec < 10)
		std::cout << "0";
	std::cout << local_time->tm_sec << "] ";
}

int	Account::getNbAccounts( void ){return (_nbAccounts);}
int	Account::getTotalAmount( void ){return (_totalAmount);}
int	Account::getNbDeposits( void ){return (_totalNbDeposits);}
int	Account::getNbWithdrawals( void ){return (_totalNbWithdrawals);}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}
int		Account::checkAmount( void )const {return(1);}

void	Account::displayStatus( void )const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
