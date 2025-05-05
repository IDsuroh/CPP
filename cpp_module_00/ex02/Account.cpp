#include "Account.hpp"
#include <iostream>
#include <ctime>

// Defining the four static counters
int Account::_nbAccounts            =   0;
int Account::_totalAmount           =   0;
int Account::_totalNbDeposits       =   0;
int Account::_totalNbWithdrawals    =   0;

// function to print a timestamp (YYYYMMDD_HHMMSS)
void    Account::_displayTimestamp(void)    {
    std::time_t now =   std::time(NULL);
    std::tm*    tm  =   std::localtime(&now);
    char    buf[16];
    std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", tm);
    std::cout << '[' << buf << "] ";
}

// Constructor & Destructor
Account::Account(int initial_deposit)
    :   _accountIndex   (_nbAccounts),
        _amount         (initial_deposit),
        _nbDeposits     (0),
        _nbWithdrawals  (0)
{
    ++_nbAccounts;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout
        << "index:"     << _accountIndex
        << ";amount:"   << _amount
        << ";created\n";
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout
        << "index:"     << _accountIndex
        << ";amount:"   << _amount
        << ";closed\n";
}

// Static getters
int Account::getNbAccounts(void)        {return _nbAccounts;}
int Account::getTotalAmount(void)       {return _totalAmount;}
int Account::getNbDeposits(void)        {return _totalNbDeposits;}
int Account::getNbWithdrawals(void)     {return _totalNbWithdrawals;}

// Static method for displaying the bank info
void    Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout
        << "accounts:"       << _nbAccounts
        << ";total:"        << _totalAmount
        << ";deposits:"     << _totalNbDeposits
        << ";withdrawals:"  << _totalNbWithdrawals
        << std::endl;
}

// Deposit logic
void    Account::makeDeposit(int deposit)   {
    _displayTimestamp();
    std::cout
        << "index:"     << _accountIndex
        << ";p_amount:" << _amount
        << ";deposit:"  << deposit;
    _amount         += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;
    _totalAmount    += deposit;
    std::cout
        << ";amount:"       << _amount
        << ";nb_deposits:"  <<_nbDeposits
        << std::endl;
}

// Withdrawal logic
bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout
        << "index:"     << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:";
    if (withdrawal > _amount)   {
        std::cout << "refused\n";
        return false;
    }
    _amount         -= withdrawal;
    ++_nbWithdrawals;
    ++_totalNbWithdrawals;
    _totalAmount    -= withdrawal;
    std::cout
        << withdrawal
        << ";amount:"           << _amount
        << ";nb_withdrawals:"   << _nbWithdrawals
        << std::endl;
    return true;
}

// Per-account status & check
int Account::checkAmount(void) const   {
    return _amount;
}

void    Account::displayStatus(void) const  {
    _displayTimestamp();
    std::cout
        << "index:"         << _accountIndex
        << ";amount:"       << _amount
        << ";deposits:"     << _nbDeposits
        << ";withdrawals:"  << _nbWithdrawals
        << std::endl;
}