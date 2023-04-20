#pragma once
#include "LibraryLinkedList.h"
#include "Book.h"
#include "LibraryMedia.h"
#include "Newspaper.h"
#include "Periodical.h"
#include "ConferenceJournal.h"
#include "Author.h"
#include  "Publisher.h"
#include <vector>

#include <fstream>

/*This class is meant to store information that will be used throughout the users session
and to load and save data from our txt files into linked lists of apporitate types*/
class CurrentSessionInfo
{
private:
	static bool isUserAdmin;
	//static LinkedList<Book> bookList;
	//static LinkedList<ConferenceJournal> journalList;
	//static LinkedList<Newspaper> newspaperList;
	//static LinkedList<Periodical> periodicalList;
	//static LinkedList<Author> authorList;
	//static LinkedList<Publisher> publisherList;
	
	//User currUser;
public:
	static vector<Author> authorList;
	static vector<Publisher> pubList;
	static vector<Book> bookList;
	static void SetAdmin(bool isAdmin);
	static bool CheckIfAdmin();
	//void SetUser();
	//User GetCurrUser();
	static void LoadInventory(bool generateDummyData);
	static void SaveInventory();
	static void GenerateDummyData();

	template<typename T>
	static void LoadData(string fileName, vector<T>& list);

	template<typename T>
	static void SaveData(string fileName, vector<T>& list);
	static LinkedList<Book> GetBookList();
	
};


