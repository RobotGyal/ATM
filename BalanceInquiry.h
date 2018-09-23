//balance inquiry header file
#pragma once
#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H
#include "Transaction.h"

//balance inquiry class
class BalanceInquiry : public Transaction
{
public:
	BalanceInquiry(int, Screen &, BankDatabase&);  //constructor
	virtual void execute();   //performs action
};

#endif