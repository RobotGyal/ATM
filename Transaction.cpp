//Transactin member functions
#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"
using namespace std;

//constructor
Transaction::Transaction(int userAccountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase) 
	: accountNumber(userAccountNumber), screen(atmScreen), bankDatabase(atmBankDatabase)
{

}

//gets account numnber
int Transaction::getAccountNumber() const
{
	return accountNumber;
}

//return screen
Screen &Transaction::getScreen() const
{
	return screen;
}

//returns database
BankDatabase &Transaction::getBankDatabase() const
{
	return bankDatabase;
}