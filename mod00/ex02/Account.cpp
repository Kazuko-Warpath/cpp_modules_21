#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account() {}

Account::Account(int initial_deposit) {
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
//    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;
}

Account::~Account() {
//    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << std::setfill('0')
                     << std::setw(4)<< (now->tm_year + 1900)
                     << std::setw(2)<< (now->tm_mon + 1)
                     << std::setw(2) << now->tm_mday << "_"
                     << std::setw(2) << now->tm_hour
                     << std::setw(2) << now->tm_min
                     << std::setw(2) << now->tm_sec << "] ";
}

void Account::displayAccountsInfos() {
//    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
//    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
//    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit
              << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
//    _displayTimestamp();
    if (_amount < withdrawal) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    } else {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:"
                << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}

int Account::checkAmount() const {
    return _amount;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}