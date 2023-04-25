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
	static string BOOK_FILE_PATH;
	static string NEWS_FILE_PATH;
	static string PERIODICAL_FILE_PATH;
	static string JOURNAL_FILE_PATH;
	//User currUser;
public:
	static vector<LibraryMedia*> mediaList;
	static vector<Author> authorList;
	static vector<Publisher> pubList;
	static vector<Book> bookList;
	static void SetAdmin(bool isAdmin);
	static bool CheckIfAdmin();
	//void SetUser();
	//User GetCurrUser();
	static void LoadAllData();
	static void SaveAllData();
	static void GenerateDummyData();
	static vector<unique_ptr<LibraryMedia>> GetLibraryInventory();

	template<typename T>
	static void LoadData(string fileName, vector<T>& list);

	//Overload so we can load in all of our media into 1 list
	template<typename T>
	static void LoadData(string fileName);

	template<typename T>
	static void SaveData(string fileName, vector<T>& list);

	//Overloading function so that we can save multiple types of library media in one list
	static void SaveData(); //This is to save our media data, since we need special logic for it
};


