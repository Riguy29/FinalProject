#ifndef GUESTLOGIN_H
#define GUESTLOGIN_H

//#include "MainLogin.h"
#include "InventoryScreen.h"
//#include "LibraryMedia.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>


class GuestLogin
{
private:
	Date date;
public:
	GuestLogin();
	~GuestLogin();
	static bool isGuest(bool guest);
	static void buy();

};

#endif // !GUESTLOGIN_H
