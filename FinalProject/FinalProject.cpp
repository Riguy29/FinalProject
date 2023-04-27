
#include "LibraryLinkedList.cpp"
#include "LibraryMedia.h"
#include "CurrentSessionInfo.h"
#include "MainLogin.h"
#include "GuestLogin.h"

#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdlib.h>


int main()
{
	//CurrentSessionInfo::GenerateDummyData();
	CurrentSessionInfo::LoadAllData();
	CurrentSessionInfo::pubList;
	CurrentSessionInfo::mediaList;
	/*
	//TEST
	cout << endl;
	cout << CurrentSessionInfo::mediaList.size();
	//END TEST
	*/
	Login login;
	GuestLogin guest;
	//guest.receipt();

	login.printMenu();
	return 0;
}