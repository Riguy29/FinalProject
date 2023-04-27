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
	void UpdateMedia()const;
	void AddMedia()const;
	void SearchForMedia()const;
	void CheckoutBook();
	void PrintMenu()const;
	void SearchByTitle() const;
	void SearchByAuthor() const;
	void SearchByDepartment() const;
	void SearchBySubject() const;
	void SearchByPublisherName() const;
	void SearchByPrice() const;
	void SearchByPublisherAddress() const;
	void ConfirmMediaCheckout() const;
	void MediaInteractionMenu(LibraryMedia& selectedMedia);
	void PrintMatchingMedia(vector<LibraryMedia*> mediaList) const;
	void EditMedia(LibraryMedia* selectedMedia) const;
private:
	string recordTxtFile = "InventoryRecord.txt";
	vector<int> MediaID;
	vector<string> MediaTitle;
	vector<double> MediaPrice;
};

#endif