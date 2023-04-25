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
	void SearchForMedia()const;
	void CheckoutBook();
	void printMenu()const;
	void SearchByTitle() const;
	void SearchByAuthor() const;
	void SearchByDepartment() const;
	void SearchBySubject() const;
	void SearchByPublisherName() const;
	void SearchByPrice() const;
	void SearchByPublisherAddress() const;

	void PrintMatchingMedia(vector<LibraryMedia*> mediaList) const;
	void EditMedia(LibraryMedia* selectedMedia) const;
private:
	string recordTxtFile = "InventoryRecord.txt";
};

#endif