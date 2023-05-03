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
#include <iomanip>
#include "Date.h"
Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}
Date::Date(const Date& copyDate)
{
    month = copyDate.month;
    day = copyDate.day;
    year = copyDate.year;
}
;

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
    
    //seconds in a day
    time_t secInDay = 86400;
  
    //setting due date to 7 days
    time_t dueDate = now + (secInDay * 7);
    // Char array for ctime_s to get time to compile properly using C++ 20
    // This char array holds the string of what the current time is
   
    char currTime[26];
   // char due[26];

    // Get the current time and convert to string, storing it in the str char array
    ctime_s(currTime, sizeof currTime, &now);
   // ctime_s(due, sizeof due, &dueDate);


    cout << currTime;//current time
}

/*void Date::CalculateFee(time_t checkedOut, time_t dueDate, time_t currentTime) {
    //seconds in a day
    time_t secInDay = 86400;
    double fee1, fee2;
    time_t diff = 86400;// currentTime - dueDate;
    double rate1 = 0.15;//rate for first 7 days
    time_t sevenDaySec = secInDay * 7;
    double rate2 = 0.25;//rate for 8 or more days
    fee1 = 10;// ((static_cast<double>(sevenDaySec) - static_cast<double>(diff)) / static_cast<double>(secInDay))* rate1;
    fee2 = 5;// (static_cast<double>(currentTime) - (static_cast<double>(sevenDaySec) - static_cast<double>(diff)) / static_cast<double>(secInDay))* rate2;

    if (diff > 0) {
        cout << "Your book is late." << endl;
        if (diff <= sevenDaySec) {            
            cout << "Your late fee is $" << fee1 << end;
        }
        else if (diff > sevenDaySec) {  
            
            cout << "Your late fee is $" << fee2 << endl;
        }
    }
    else {
        cout << "Thank you for returning your book on time." << endl;
    }
    cout << diff;
    
}
*/

void Date::printDate()const {
   // cout << "The local date and time is: ";
    TimeFunction();
    cout << endl;
}

