#pragma once

#include<iostream>
#include<string>
using namespace std;

class PatronLogin
{
public:
	PatronLogin();
	~PatronLogin();
	void borrow();
	void placeHold();
	void renew();
	double lateFee();
	void printMenu()const;

};
