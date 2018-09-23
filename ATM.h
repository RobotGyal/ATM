//Header for ATM
#ifndef ATM_H
#define ATM_H

#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "BankDatabase.h"
class Transaction;

class ATM {
public:
	ATM();  //constructor
	void run();   //starts the atm program
private:
	bool userAuthenticated;   //to msee it the user is valid
	int currentAccountNumber;  //users account number
	Screen screen;    //atm screen
	Keypad keypad;   //atm keypad
	CashDispenser cashDispenser;   //atm cach dispenser
	DepositSlot depositSlot;    //atm deposit slot
	BankDatabase bankDatabase;   //information database

	void authenticateUser();    
	void performTransactions();  //does transactions
	int displayMainMenu() const;    //displays main menu

	//returns object of the class
	Transaction *createTransaction(int);   
};

#endif
