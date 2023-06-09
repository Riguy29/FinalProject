#pragma once

#include <iostream>
#include <string>
#include "CheckedoutMedia.h"
#include "CurrentSessionInfo.h"
#include "Newspaper.h"
#include "ConferenceJournal.h"
#include "Periodical.h"
#include "Book.h"
#include "GuestLogin.h"
//#include "User.h"
#include <vector>
#include <fstream>

using namespace std; 

class InventoryScreen {
public:
	static void AddMedia();
	static void SearchForMedia();
	static void printMenu();
	static void SearchByTitle();
	static void SearchByAuthor();
	static void SearchByDepartment();
	static void SearchBySubject() ;
	static void SearchByPublisherName() ;
	static void SearchByPrice() ;
	static void SearchByPublisherAddress();
	static void ConfirmMediaCheckout();
	static void MediaInteractionMenu(LibraryMedia* selectedMedia, bool& mediaDeleted);
	static void PrintMatchingMedia(vector<LibraryMedia*> mediaList);

	static void EditMediaDataMenu(LibraryMedia* selectedMedia);
	
private:
	static string recordTxtFile;
	static vector<LibraryMedia*> mediaToCheckoutOrBuy;
};
