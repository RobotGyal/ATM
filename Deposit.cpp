//Deposit member functions
#include <iostream>
#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"
using namespace std;

//cancel options
const static int CANCELED = 0;


//constructor
Deposit::Deposit(int userAccountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase, Keypad &atmKeypad, DepositSlot &atmDepositSlot)
	:Transaction(userAccountNumber, atmScreen, atmBankDatabase), keypad(atmKeypad), depositSlot(atmDepositSlot)
{

}

//runs file
void Deposit::execute()
{
	BankDatabase &bankDatabase = getBankDatabase();
	Screen &screen = getScreen();

	amount = promptForDepositAmount();

	//check to see if user wants to cancel
	if (amount != CANCELED)
	{
		cout << "Please insert a deposit envelope containing " << amount << "in the depoist slot." << endl;

		bool envelopeRecieved = depositSlot.isEnvelopeRecieved();

		if (envelopeRecieved)
		{
			cout << "Your envelope has been accepted. \nThe money will be available after verification of cash and checks." << endl;

			bankDatabase.credit(getAccountNumber(), amount);
		}
		else
		{
			cout << "\n You did not insert an envelope, so the transaction has been canceled." << endl;
		}
	}
	else
	{
		cout << "\nCanceleing Transaction..." << endl;
	}
}

//prompt user to enter deposit amount
double Deposit::promptForDepositAmount() const
{
	Screen &screen = getScreen();

	cout << "Please enter deposit amount in CENTS (or 0 to cancel)" << endl;
	int input;
	cin >> input;

	if (input == CANCELED)
		return CANCELED;
	else
	{
		return static_cast<double>(input) / 100;
	}
}
