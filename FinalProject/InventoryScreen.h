#pragma once
#include <iostream>
#include <string>
#include "MenuScreen.h"
#include "CheckedoutMedia.h"
#include <vector>
#include <fstream>

using namespace std; 

class InventoryScreen //: public MenuScreen
{
public:
	void SearchForBook();
	void CheckoutBook();
	void printMenu();
	void SearchByTitle();
	void SearchByAuthor(string targetAuthor);
private:
	string recordTxtFile = "InventoryRecord.txt";
};

