#ifndef INVENTORYSCREEN_CPP
#define INVENTORYSCREEN_CPP




#include "InventoryScreen.h"

void InventoryScreen::SearchForBook()
{
	int choice;
	bool validChoice = false;
	do
	{
		cout << "How would like to search for media?" << endl;
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
			SearchByTitle();
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
	} while (true);
	//If search find items, return the top 5 items
}
void InventoryScreen::printMenu() {
	int choice =0;
	bool validChoice =false;
	do
	{
		cout << "What would you like to do?" << endl;
		cout << "1. Search inventory" << endl;
		cout << "2. Exit menu" << endl;
	} while (true);
	

}
void InventoryScreen::SearchByTitle()
{
	string title;
	fstream inventoryFile;
	cout << "Enter the title of the book you are looking for" << endl;
	cin >> title;
	inventoryFile.open(recordTxtFile);
	if (!inventoryFile.is_open()) {
		cout << "Error";
	}
	else {

	}
}

#endif // !INVENTORYSCREEN_CPP