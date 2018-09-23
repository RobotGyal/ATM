//Account header file
#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

//account class
class Account
{
public:
	Account(int, int, double, double);  //constructor
	bool validatePIN(int) const;   //checks pin for validation
	double getAvailableBalance() const;  //gets balance that can be accessed
	double getTotalBalance() const;    //get total balance
	void credit(double);   //add to account balance
	void debit(double);   //subtracts from account balance
	int getAccountNumber() const;   //returns account number
private:
	int accountNumber; 
	int pin;
	double availableBalance;
	double totalBalance;
};

#endif
