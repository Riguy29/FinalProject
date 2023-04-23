/*#include "Date.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
//string Date::GetDate()
//{
  //  return string();
//}


*/
/**************************************************************
 * The implementation of functions in the Date class          *
 **************************************************************/

#include "Date.h"
Date::Date() {};

Date::Date(int m, int d, int y)
    : month(m), day(d), year(y) {
    if ((month < 1) || (month > 12))
    {
        cout << "Month is out of range. ";
        assert(false);
    }
    int daysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31,
                             31, 30, 31, 30 ,31 };
    if ((day < 1) || (day > daysInMonths[month]))
    {
        cout << "Day out of range! ";

    }
    if ((year < 1900) || (year > 2099))
    {
        cout << "Year out of range! ";
    }
}

Date :: ~Date() {}

void Date::print() const {
    cout << month << "/" << day << "/" << year << endl;
}

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
   // cout << "The local date and time is: ";
    TimeFunction();
    cout << endl;
}