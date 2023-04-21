
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
	
	//cout << "The local date and time is: " << str << endl;

	//TEST
	//CurrentSessionInfo::GenerateDummyData();
	//CurrentSessionInfo::LoadInventory(true);
	//cout << CurrentSessionInfo::pubList.size() << endl;
	//cout << *CurrentSessionInfo::authorList.at(1).name << endl;
	//CurrentSessionInfo::bookList.at(0).ToString();
	//END TEST

	Login login;
	//AdminMenu adminMenu;
	//PatronLogin patron;

	login.printMenu();

	//opeing current user in order to open the correct menu
	/*string line;
	ifstream currUser("currentUser.txt");
	if (currUser.is_open()) {
		getline(currUser, line);
		if (line.at(0) == 'M') {

			adminMenu.printMenu();
			CurrentSessionInfo::SetAdmin(true);
		}
		else if (line.at(0) == 'E' || line.at(0) == 'S') {
			patron.printMenu();
		}
		else {
			cout << "Have a Great Day!" << endl;			
		}
	}
	else {
		cout << "Guest Login" << endl;
		currUser.close();
	}*/
	/*
	LibraryMedia book1("Harry Potter", "book", "978-0-545-79142-7", "Fantasy", "Young Adult", "First illustrated edition", 2, 24.99, "J.K. Rowling", "Bloomsbury Publishing PLC");
	
	LinkedList<LibraryMedia> mediaList;
	mediaList.insertItem(book1);
	mediaList.printList();
	*/
	return 0;
}