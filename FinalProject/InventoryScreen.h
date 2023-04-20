#ifndef INVENTORYSCREEN_H
#define INVENTORYSCEEN_H

#include <iostream>
#include <string>
#include "CheckedoutMedia.h"
#include "CurrentSessionInfo.h"
#include "Newspaper.h"
#include "ConferenceJournal.h"
#include "Periodical.h"
#include "Book.h"
#include <vector>
#include <fstream>



using namespace std; 

class InventoryScreen 
{
public:
	void UpdateMedia();
	void AddMedia();
	void SearchForMedia();
	void CheckoutBook();
	void printMenu();
	void SearchByTitle(LibraryMedia::mediaTypes type);
	void SearchByAuthor(string targetAuthor);

	void PrintMatchingMedia(vector<Book*> mediaList);
	void PrintMatchingMedia(vector<ConferenceJournal> mediaList);
	void PrintMatchingMedia(vector<Newspaper> mediaList);
	void PrintMatchingMedia(vector<Periodical> mediaList);
private:
	string recordTxtFile = "InventoryRecord.txt";
};

#endif