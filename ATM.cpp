//ATM.cpp
//Member functions definitions for class ATM

#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Deposit.h"
#include <iostream>
using namespace std;

enum MenuOption
{
	BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT
};

ATM::ATM()
	:userAuthenticated(false), currentAccountNumber(0)
{
	//empty for constructor
}


// runs the program
void ATM::run()
{
	while (true)
	{
		//if not verified
		while (!userAuthenticated)
		{
			cout << "\nWelcome!" << endl;
			authenticateUser();
		}
		performTransactions();
		userAuthenticated = false;
		currentAccountNumber = 0;
		cout << "\nThank you! Bye!" << endl;
	}
}

//trys to verify user based on data
void ATM::authenticateUser()
{
	cout << "\nPlease enter your account number: " << endl;
	int accountNumber;
	cin >> accountNumber;
	cout << "\nEnter your Pin: " << endl;
	int pin;
	cin >> pin;

	userAuthenticated = bankDatabase.authenticateUser(accountNumber, pin);

	//checks if authentication succeeded
	if (userAuthenticated)
	{
		currentAccountNumber = accountNumber;
	}
	else
		cout << "Invalid account number or PIN. Try again." << endl;
}

//display the main menu and selections
void ATM::performTransactions()
{
	Transaction *currentTransactionPtr;

	bool userExited = false;

	//user hasnt exited system
	while (!userExited)
	{
		//show main menu and selection
		int mainMenuSelection = displayMainMenu();

		switch (mainMenuSelection)
		{
		case BALANCE_INQUIRY:
		case WITHDRAWAL:
		case DEPOSIT:
			currentTransactionPtr = createTransaction(mainMenuSelection);

			currentTransactionPtr->execute();
			
			delete currentTransactionPtr;

			break;
		case EXIT:
			cout << "\nExiting the Application..." << endl;
			userExited = true;
			break;
		default:
			cout << "\nYou didn't enter a valid selection. Try again." << endl;
			break;

		}
	}
}

//display main menu and options
int ATM::displayMainMenu() const
{
	cout << "\nMain Menu: " << endl;
	cout << "1 - View Balance" << endl;
	cout << "2 - Withdraw Cash" << endl;
	cout << "3 - Deposit Funds" << endl;
	cout << "4 - Exit\n" << endl;
	cout << "\nMake a selection: " << endl;
	int print;
	cin >> print;
	return print;
}


Transaction *ATM::createTransaction(int type)
{
	Transaction *tempPtr;

	//says what type of transaction to make
	switch (type)
	{
	case BALANCE_INQUIRY:
		tempPtr = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);
		break;
	case WITHDRAWAL:
		tempPtr = new Withdrawal(currentAccountNumber, screen, bankDatabase, keypad, cashDispenser);
		break;
	case DEPOSIT:
		tempPtr = new Deposit(currentAccountNumber, screen, bankDatabase, keypad, depositSlot);
		break;
	}
	return tempPtr;
}