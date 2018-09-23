//Screen member functions
#include <iostream>
#include <iomanip>
#include <string>
#include "Screen.h"
using namespace std;

//displays a message to screen
void Screen::displayMessage(string message) const
{
	cout << message;
}

//displays a message to the screen with a new line
void Screen::displayMessageLine(string message) const
{
	cout << message << endl;
}

//displays a numeric double to the screen
void Screen::displayDollarAmount(double amount) const
{
	cout << fixed << setprecision(2) << "$" << amount;
}