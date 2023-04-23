#ifndef GUESTLOGIN_H
#define GUESTLOGIN_H

//#include "MainLogin.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>


class Guest //: public Login
{
private:
	//string fName;
	//string lName;
public:
	Guest();
	~Guest();
	//LinkedList<Guest> guestlist;
	void borrow();
	void checkout();
	void returnItems();
	void printMenu()const;

};

#endif // !GUESTLOGIN_H
