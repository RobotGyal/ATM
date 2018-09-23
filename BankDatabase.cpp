//bank database member functions
#include "BankDatabase.h"

using namespace std;

//constructor
BankDatabase::BankDatabase()
{
	//two test accounts
	Account account1(852369, 852147, 1000.0, 1200.0);
	Account account2(654123, 987456, 2000.0, 2200.0);

	accounts.push_back(account1);
	accounts.push_back(account2);
}

//get information for the chosen account
Account * BankDatabase::getAccount(int accountNumber)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			return &accounts[i];
	}
	return NULL;
}

//checks to see if user input is the same as in the sysytem
bool BankDatabase::authenticateUser(int userAccountNumber, int userPIN)
{
	Account * const userAccountPtr = getAccount(userAccountNumber);

	if (userAccountPtr != NULL)
		return userAccountPtr->validatePIN(userPIN);
	else
		return false;
}

//returns available balance
double BankDatabase::getAvailableBalance(int userAccountNumber)
{
	Account * const userAccountPtr = getAccount(userAccountNumber);
	return userAccountPtr->getAvailableBalance();
}

//returns total balance
double BankDatabase::getTotalBalance(int userAccountNumber)
{
	Account * const userAccountPtr = getAccount(userAccountNumber);
	return userAccountPtr->getTotalBalance();
}

//adds to the account
void BankDatabase::credit(int userAccountNumber, double amount)
{
	Account * const userAccountPtr = getAccount(userAccountNumber);
	userAccountPtr->credit(amount);
}

//subtracts from the account
void BankDatabase::debit(int userAccountNumber, double amount)
{
	Account * const userAccountPtr = getAccount(userAccountNumber);
	userAccountPtr->debit(amount);
}