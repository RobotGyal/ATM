//Keypad member functions
#include <iostream>
#include "Keypad.h"
using namespace std;

//returns the value that was taken from the user
int Keypad::getInput()const
{
	int input;
	cin >> input;
	return input;
}