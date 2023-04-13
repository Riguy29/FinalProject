#pragma once
#include "LibraryLinkedList.h"
#include "Book.h"
#include "LibraryMedia.h"
#include "Newspaper.h"
#include "Periodical.h"
#include "ConferenceJournal.h"

#include <fstream>

/*This class is meant to store information that will be used throughout the users session
and to load and save data from our txt files into linked lists of apporitate types*/
class CurrentSessionInfo
{
private:
	static bool isUserAdmin;
	static LinkedList<Book> bookList;
	static LinkedList<ConferenceJournal> journalList;
	static LinkedList<Newspaper> newspaperList;
	static LinkedList<Periodical> periodicalList;

	//User currUser;
public:
	static void SetAdmin(bool isAdmin);
	static bool CheckIfAdmin();
	//void SetUser();
	//User GetCurrUser();
	static void LoadInventory();
	static void SaveInventory();

	static LinkedList<Book> GetBookList();
	
};

