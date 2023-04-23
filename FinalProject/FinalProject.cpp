
#include "LibraryLinkedList.cpp"
#include "LibraryMedia.h"
#include "CurrentSessionInfo.h"
#include "MainLogin.h"

#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdlib.h>


int main()
{
	//TEST
	CurrentSessionInfo::GenerateDummyData();
	CurrentSessionInfo::LoadInventory(true);
	//cout << CurrentSessionInfo::pubList.size() << endl;
	//cout << *CurrentSessionInfo::authorList.at(1).name << endl;
	CurrentSessionInfo::mediaList.at(3)->ToString();
	cout << endl;
	//cout << CurrentSessionInfo::mediaList.size();
	//END TEST

	Login login;
	//AdminMenu adminMenu;
	//PatronLogin patron;

	login.printMenu();

	return 0;
}