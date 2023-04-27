/*
#include <chrono>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
using namespace chrono;

class Date
{
private:
	//day d;
	//month m;
	//year y;
public:
	//string GetDate();
	
};
*/
/**************************************************************
 * The interface file for date.h class                        *
 **************************************************************/

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <cassert>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;
public:
	Date();
	Date(const Date& copyDate);
	Date(int month, int day, int year);
	~Date();
	void print() const;
	static void TimeFunction();
	void printDate()const;
};

#endif
