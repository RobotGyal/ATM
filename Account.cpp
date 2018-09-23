//Account member functions
#include "Account.h"

//constructor
Account::Account(int theAccountNumber, int thePIN, double theAvailableBalance, double theTotalBalance) 
	: accountNumber(theAccountNumber), pin(thePIN), availableBalance(theAvailableBalance), totalBalance(theTotalBalance)
{

}

//checks if pin ins valid
bool Account::validatePIN(int userPIN) const
{
	if (userPIN == pin)  //if yes return true
		return true;
	else
		return false;   //otherwise say no
}

//returns available balance
double Account::getAvailableBalance() const
{
	return availableBalance;
}

//returns total balance
double Account::getTotalBalance() const
{
	return totalBalance;
}

//adds to the total balance
void Account::credit(double amount)
{
	totalBalance += amount;
}

//subtracts from the balance
void Account::debit(double amount)
{
	availableBalance -= amount;
	totalBalance -= amount;
}

//returns account number
int Account::getAccountNumber() const
{
	return accountNumber;
}