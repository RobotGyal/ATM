//Cash dispenser member functions
#include "CashDispenser.h"

CashDispenser::CashDispenser()
  //count is set as default
{
	count = INITIAL_COUNT;
}

void CashDispenser::dispenseCash(int amount)
{
	int billsRequired = amount / 20;  //number of 20s remaining
	count -= billsRequired;  //updats amount
}

bool CashDispenser::isInsufficientCashAvailable(int amount) const
{
	int billsRequired = amount / 20;   //sees if enough 20 are available

	if (count >= billsRequired)
		return true;
	else
		return false;
}