//Withdrawal member functions
#include <iostream>
#include "Withdrawal.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"
using namespace std;

//menu options to cancel
const static int CANCELED = 6;

//constructor
Withdrawal::Withdrawal(int userAccountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase, Keypad &atmKeypad, CashDispenser &atmCashDispenser)
	:Transaction(userAccountNumber, atmScreen, atmBankDatabase), keypad(atmKeypad), cashDispenser(atmCashDispenser)
{

}

//runs program
void Withdrawal::execute()
{
	bool cashDispensed = false;  //cash not dispensed
	bool transactionCanceled = false;   //transaction not canceled

	BankDatabase &bankDatabase = getBankDatabase();
	Screen &screen = getScreen();

	do
	{
		int selection = displayMenuOfAmounts();  //get withdrawal amount from user

		if (selection != CANCELED)  //check if the user canceled
		{
			amount = selection;

			double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());  //pulls account info from bank database

			if (amount <= availableBalance)
			{
				if (cashDispenser.isInsufficientCashAvailable(amount))  
				{
					bankDatabase.debit(getAccountNumber(), amount);

					cashDispenser.dispenseCash(amount);
					cashDispensed = true;

					cout << "Please take your cash from the dispenser" << endl;
				}
				else
					cout << "Insufficient cash available in the ATM" << "\nPlease choose a smaller amount" << endl;
			}
			else
			{
				cout << "Insuffient funds in your account." << "\nPlease choose a smaller amount. " << endl;
		}
	}
	else
	{
		cout << "Canceling transaction..." << endl;
		transactionCanceled = true;
	}
}
	while (!cashDispensed && !transactionCanceled);
}

int Withdrawal::displayMenuOfAmounts() const
{
	int userChoice = 0;

	Screen &screen = getScreen();

	int amounts[] = { 0, 20, 40 , 60, 100, 200 };

	while (userChoice == 0)
	{
		cout << "\n Withdrawal Options:" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $40" << endl;
		cout << "3 - $60" << endl;
		cout << "4 - $100" << endl;
		cout << "5 - $200" << endl;
		cout << "6 - Cancel Transaction" << endl;
		cout << "Choose a withdrawal options(1-6): " << endl;

		int input;
		cin >> input;

		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			userChoice = amounts[input];
			break;
		case CANCELED:
			userChoice = CANCELED;
			break;
		default:
			cout << "\nInvalid selection. Try again." << endl;
		}
	}
	return userChoice;
}
