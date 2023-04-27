#ifndef GUESTLOGIN_H
#define GUESTLOGIN_H

//#include "MainLogin.h"
//#include "InventoryScreen.h"
//#include "LibraryMedia.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>


class Guest 
{
private:
	Date date;
public:
	Guest();
	~Guest();
	static void buy();
	void receipt()const;

};

#endif // !GUESTLOGIN_H
