#include "Date.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
//string Date::GetDate()
//{
  //  return string();
//}

void Date::TimeFunction() {
	// current date/time based on current system
	time_t now = time(0);

	// Char array for ctime_s to get time to compile properly using C++ 20
	// This char array holds the string of what the current time is
	char str[26];

	// Get the current time and convert to string, storing it in the str char array
	ctime_s(str, sizeof str, &now);
	cout << str;
	
}

void Date::printDate()const {
	cout << "The local date and time is: ";
	TimeFunction();
	cout << endl;
}