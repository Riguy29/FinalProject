
#include "LibraryLinkedList.cpp"
#include "LibraryMedia.h"
#include "AdminMenu.h"
#include "CurrentSessionInfo.h"
#include "MainLogin.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void TimeFunction() {
	// current date/time based on current system
	time_t now = time(0);

	// Char array for ctime_s to get time to compile properly using C++ 20
	// This char array holds the string of what the current time is
	char str[26];

	// Get the current time and convert to string, storing it in the str char array
	ctime_s(str, sizeof str, &now);

	cout << "The local date and time is: " << str << endl;
}

int main()
{
	//THIS IS A TEST, REMOVE AFTER USAGE
	string search;
	CurrentSessionInfo::LoadInventory();
	//Node<LibraryMedia>* currBook = CurrentSessionInfo::GetBookList().GetHead();
	//if (currBook->data.GetTitle() == "") cout << "TEST";
	//cout << currBook->data.GetTitle() << endl;
	//while (currBook != NULL)
	//{
	//	
	//	currBook = currBook->next;
	//}
	//END TEST
	Login login;
	login.printMenu();

	//opeing current user in order to open the correct menu
	string line;
	ifstream currUser("currentUser.txt");
	if (currUser.is_open()) {
		getline(currUser, line);
		if (line.at(0) == 'M') {
			AdminMenu adminMenu;
			adminMenu.printMenu();
			CurrentSessionInfo::SetAdmin(true);
		}
		else if (line.at(0) == 'E' || line.at(0) == 'S')
			cout << "Menu Under Construction";
		currUser.close();
	}


	/*
	LibraryMedia book1("Harry Potter", book, "978-0-545-79142-7", "Fantasy", "Young Adult", "First illustrated edition", 2, 24.99), "J.K. Rowling", "Bloomsbury Publishing PLC");
	
	LinkedList<LibraryMedia> mediaList;
	mediaList.insertItem(book1);
	mediaList.printList();
	*/
	return 0;
}