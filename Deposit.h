//deposit header file
#pragma once
#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "Transaction.h"

class Keypad;
class DepositSlot;

//deposit class
class Deposit : public Transaction
{
public:
	Deposit(int, Screen &, BankDatabase &, Keypad &, DepositSlot &);  //constructor
	virtual void execute();  
private:
	double amount;
	Keypad &keypad;  //reference keypad
	DepositSlot &depositSlot;   //references deposit slot
	double promptForDepositAmount() const;  //get amount fro muser
};

#endif
