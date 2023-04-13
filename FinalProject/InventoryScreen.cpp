#ifndef INVENTORYSCREEN_CPP
#define INVENTORYSCREEN_CPP
#include "InventoryScreen.h"

void InventoryScreen::AddMedia()
{
	//XMLDocument inventoryXML;
	////FIXME: Right now we are just assuming it will load right
	//XMLError eResult = inventoryXML.LoadFile("InventoryRecord.xml"); 
	int choice =0;
	bool isValid = true;
	Book book;
	Newspaper newspaper;
	ConferenceJournal journal;
	
	do
	{
		cout << "What kind of media would you like to add?" << endl;
		cout << "1. Book" << endl;
		cout << "2. Newspaper" << endl;
		cout << "3. Journal" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			book.SetTitle();
			book.SetISBN();
			book.SetPrice();
			break;
		case 2:
			newspaper.SetTitle();
		default:
			break;
		}
	} while (true);



}

void InventoryScreen::SearchForMedia()
{
	int choice;
	bool validChoice = false;
	LibraryMedia::mediaTypes tempMediaType;
	string searchType = "ERROR";
	do
	{
		cout << "What media would like to search for?" << endl;
		cout << "1. Books" << endl;
		cout << "2. Newspapers" << endl;
		cout << "3. Journals" << endl;
		cout << "4. Periodicals" << endl;
		cout << "5. Return" << endl;
		cin >> choice;
		validChoice = true; //Assume choice is valid
		switch (choice)
		{
		case 1:
			searchType = "Books";
			tempMediaType = LibraryMedia::book;
			break;
		case 2:
			searchType = "Journals";
			tempMediaType = LibraryMedia::book;
			break;
		case 3:
			searchType = "Newspapers";
			tempMediaType = LibraryMedia::book;
			break;
		case 4:
			searchType = "Periodicals";
			tempMediaType = LibraryMedia::book;
			break;
		case 5:
			return;
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
	} while (!validChoice);
	do
	{
		cout << "How would like to search for " << searchType <<"?" << endl;
		cout << "1. Search by Title" << endl;
		cout << "2. Search by Author" << endl;
		cout << "3. Search by Publisher" << endl;
		cout << "4. Search by Cateogory" << endl;
		//FIXME:: If user is admin, offer more search options
		cin >> choice;
		validChoice = true; //Assume choice is valid
		switch (choice)
		{
		case 1:
			SearchByTitle(tempMediaType);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
	} while (!validChoice);
	//If search find items, return the top 5 items
}
void InventoryScreen::printMenu() {
	int choice =0;
	bool validChoice;
	do
	{
		cout << "What would you like to do?" << endl;
		cout << "1. Checkout Media" << endl;
		if (CurrentSessionInfo::CheckIfAdmin()) {
			cout << "2. Edit Media" << endl;
			cout << "3. Add new Media" << endl;
		}
		cout << "4. Exit menu" << endl;
		cin >> choice;
		validChoice = true; //Assume choice is valid
		switch (choice)
		{
		case 1:
			SearchForMedia();
			break;
		case 2: //If a user is not an admin and selects 2, make choice invlaid
			if (CurrentSessionInfo::CheckIfAdmin()) SearchForMedia();
			break;
		case 3:
			if (CurrentSessionInfo::CheckIfAdmin()) AddMedia();
			break;
		case 4:
			return;
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
	} while (true);
	

}
void InventoryScreen::SearchByTitle(LibraryMedia::mediaTypes type)
{
	string title;
	cout << "Enter the title of the " << type << "you are looking for" << endl;
	cin >> title;
	if (type == LibraryMedia::book) {
		vector<Book> matchingBookList;
	}
	else if (type == LibraryMedia::conferenceJournal) {
		vector<ConferenceJournal> matchingJournalList;
	}

}

#endif // !INVENTORYSCREEN_CPP