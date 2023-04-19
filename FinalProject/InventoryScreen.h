#ifndef INVENTORYSCREEN_H
#define INVENTORYSCEEN_H

#include <iostream>
#include <string>
#include "CheckedoutMedia.h"
#include "CurrentSessionInfo.h"
#include "Newspaper.h"
#include "ConferenceJournal.h"
#include <vector>
#include <fstream>
#include "tinyxml2.h"


using namespace std; 

class InventoryScreen 
{
public:
	void printMenu()const;
	/*void UpdateMedia();
	void AddMedia();
	void SearchForMedia();
	void CheckoutBook();	
	void SearchByTitle();
	void SearchByAuthor(string targetAuthor);
private:
	string recordTxtFile = "InventoryRecord.txt";*/
};

#endif