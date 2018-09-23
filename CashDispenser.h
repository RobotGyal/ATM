//Cash dispenser header
#pragma once
#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H


//cahs dispenser class
class CashDispenser
{
public:
	CashDispenser();   //constructor
	void dispenseCash(int);   //dispenses cash
	bool isInsufficientCashAvailable(int) const;  //tells if theres enough cash in the account

private:
	const static int INITIAL_COUNT = 500; 
	int count;
};

#endif