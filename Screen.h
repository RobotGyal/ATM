//Screen header file
#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
using std::string;

//creates screen class
class Screen
{
public:
	//for printing information to the screen
	void displayMessage(string) const;
	void displayMessageLine(string) const;
	void displayDollarAmount(double) const;
};

#endif 