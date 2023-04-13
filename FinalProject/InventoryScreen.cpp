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
		//validChoice = true; //Assume choice is valid
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
	} while (true);
	do
	{
		cout << "How would like to search for " << searchType <<"?" << endl;
		cout << "1. Search by Title" << endl;
		cout << "2. Search by Author" << endl;
		cout << "3. Search by Publisher" << endl;
		cout << "4. Search by Cateogory" << endl;
		//FIXME:: If user is admin, offer more search options
		cout << "9. Return" << endl;
		cin >> choice;
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
			return;
		}
	} while (true);
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

		//Create vector of pointers that will point to the memory of matching books found in BookList();
		vector<Book*> matchingBookList;

		//Goes through Book list and checks for title that contain the user input
		for (int i = 0; i < CurrentSessionInfo::GetBookList().size(); i++)
		{
			if (CurrentSessionInfo::GetBookList().getItem(i).GetTitle().find(title) != string::npos) {
				Book* pNewBook = &CurrentSessionInfo::GetBookList().getItem(i);
				matchingBookList.push_back(pNewBook);
				if (matchingBookList.size() >= 5) {
					PrintMatchingMedia(matchingBookList);
				}
			}
		}
		if (matchingBookList.size() == 0) {
			cout << "No Books Found";
			return;
		}
	}
	else if (type == LibraryMedia::conferenceJournal) {
		vector<ConferenceJournal> matchingJournalList;
	}


}

void InventoryScreen::PrintMatchingMedia(vector<Book*> mediaList)
{
	
	Book* selectedBook;
	int choice=0;
	do
	{
		cout << "Select a book" << endl;
		for (int i = 1; i <= mediaList.size(); i++)
		{
			cout << i << ". ";
			mediaList.at(i-1)->ToString();
			cout << endl;
		}
		cout << "6. Return" << endl;
		cin >> choice;
		if (choice == 6) return;
		else if (mediaList.at(choice - 1) != NULL) {
			selectedBook = mediaList.at(choice - 1);
			//Open up a option to edit the book
		}
		else cout << "Invalid Selection, try again" << endl;

		

	} while (true);
}


#endif // !INVENTORYSCREEN_CPP