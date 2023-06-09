#pragma once

#include <vector>
#include <fstream>

#include "CheckedoutMedia.h"
#include "Book.h"
#include "LibraryMedia.h"
#include "Newspaper.h"
#include "Periodical.h"
#include "ConferenceJournal.h"
#include "Author.h"
#include  "Publisher.h"
#include "User.h"
#include "Staff.h"
#include "FacultyMember.h"
#include "Student.h"



/*This class is meant to store information that will be used throughout the users session
and to load and save data from our txt files into linked lists of apporitate types*/

//Forward Declaration for checkedoutMedia
class CheckedoutMedia;

class CurrentSessionInfo
{
private:
	static string BOOK_FILE_PATH;
	static string NEWS_FILE_PATH;
	static string PERIODICAL_FILE_PATH;
	static string JOURNAL_FILE_PATH;
	static string FACULTY_FILE_PATH;
	static string STAFF_FILE_PATH;
	static string STUDENT_FILE_PATH;
	static string BORROWED_MEDIA_PATH;
public:
	static bool isGuest;
	static vector<LibraryMedia*> mediaList;
	static vector<User*> userList;
	static vector<Author> authorList;
	static vector<Publisher> pubList;
	static vector<CheckedoutMedia> borrowedMediaList;
	static void LoadAllData();
	static void SaveAllData();
	static void GenerateDummyData();
	static vector<LibraryMedia*> GetLibraryInventory();
	static vector<User*> GetUsersVector();
	static User currUser;

	template<typename T>
	static void LoadData(string fileName, vector<T>& list);

	//Overload so we can load in all of our media into 1 list
	template<typename T>
	static void LoadMediaData(string fileName);

	// Load Users into vector
	template<typename T>
	static void LoadUserData(string fileName);

	//This function is used to save data for Staff, Students, and Faculty Members
	static void SaveUserData();

	//This function is used to save data for publishers, and authors
	template<typename T>
	static void SaveData(string fileName, vector<T>& list);

	//Overloading function so that we can save multiple types of library media in one list
	//Also save saves the different types of users out to a file
	static void SaveData(); //This is to save our media data, since we need special logic for it
};


