//Balance inquiry member functions
#include <iostream>
#include "BalanceInquiry.h"
#include "Screen.h"
#include "BankDatabase.h"

using namespace std;

//constructor
BalanceInquiry::BalanceInquiry(int userAccountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase) : Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{

}

//does the transaction
void BalanceInquiry::execute()
{
	//gets refernces to screen and databse
	BankDatabase &bankDatabase = getBankDatabase();
	Screen &screen = getScreen();

	double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());

	double totalBalance = bankDatabase.getTotalBalance(getAccountNumber());

	cout << "\nBalance Information:" << endl;
	cout << "Available Balance: " << endl;
	cout << availableBalance << endl;
	cout << "Total Balance:    "  << endl;
	cout << totalBalance << endl;
	cout << "  " << endl;
}
