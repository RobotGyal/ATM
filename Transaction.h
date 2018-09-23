//Transaction header file
#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Screen;
class BankDatabase;

//transaction class
class Transaction
{
public:
	Transaction(int, Screen &, BankDatabase &); //consturctor

	virtual ~Transaction(){} //virtual destructor

	int getAccountNumber() const;  //returns account number
	Screen &getScreen() const;  //reutrns screen refernce
	BankDatabase &getBankDatabase() const;  //returns bank database reference

	virtual void execute() = 0;

private:
	int accountNumber;
	Screen &screen;
	BankDatabase &bankDatabase;
};
#endif