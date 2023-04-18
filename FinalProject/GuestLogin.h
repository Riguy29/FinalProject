#ifndef GUESTLOGIN_H
#define GUESTLOGIN_H

#include <iostream>
#include <string>
#include <fstream>


class Guest {
private:
	string fName;
	string lName;
public:
	Guest();
	~Guest();
	LinkedList<Guest> guestlist;
	static void TimeFunction();
	void borrow();
	void checkout();
	void returnItems();
	void printMenu();

};
#endif // !GUESTLOGIN_H
