
//#include "LibraryLinkedList.cpp"
#include "LibraryMedia.h"
#include "CurrentSessionInfo.h"
#include "MainLogin.h"
#include "GuestLogin.h"
#include "InventoryScreen.h"

#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdlib.h>


int main()
{
	CurrentSessionInfo::GenerateDummyData();
	CurrentSessionInfo::LoadAllData();
	
	//InventoryScreen::SearchForMedia();
	Login login;
	login.printMenu();
}