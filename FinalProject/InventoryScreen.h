#pragma once
#include <iostream>
#include <string>
#include "MenuScreen.h"
#include "CheckedoutMedia.h"
#include "CurrentSessionInfo.h"
#include "Newspaper.h"
#include "ConferenceJournal.h"
#include "Book.h"
#include <vector>
#include <fstream>



using namespace std; 

class InventoryScreen //: public MenuScreen
{
public:
	void UpdateMedia();
	void AddMedia();
	void SearchForMedia();
	void CheckoutBook();
	void printMenu();
	void SearchByTitle(LibraryMedia::mediaTypes type);
	void SearchByAuthor(string targetAuthor);
private:
	string recordTxtFile = "InventoryRecord.txt";
};

