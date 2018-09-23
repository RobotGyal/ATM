//Bank Databse header file
#pragma once
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H
#include <vector>
#include "Account.h"
using namespace std;

//bank database class
class BankDatabase
{
public:
	BankDatabase();  //constructor

	bool authenticateUser(int, int);

	double getAvailableBalance(int);
	double getTotalBalance(int);
	void credit(int, double);
	void debit(int, double);
private:
	vector<Account> accounts;  //holds account number

	Account * getAccount(int);  //pointer to account object
};

#endif