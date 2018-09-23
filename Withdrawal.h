//withdrawal header file
#pragma once
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h"

class Keypad;
class CashDispenser;

//withdrawal class
class Withdrawal : public Transaction
{
public:
	Withdrawal(int, Screen &, BankDatabase &, Keypad &, CashDispenser &);  //constructor
	virtual void execute();  //runs program
private:
	int amount;
	Keypad &keypad;  //references keypad
	CashDispenser &cashDispenser;   //references cash dispenser
	int displayMenuOfAmounts() const;  //display menu
};

#endif
