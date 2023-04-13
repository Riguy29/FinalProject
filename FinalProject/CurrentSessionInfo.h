#pragma once
#include "tinyxml2.h"
#include "LibraryLinkedList.h"
#include "LibraryMedia.h"
using namespace tinyxml2;
class CurrentSessionInfo
{
private:
	static bool isUserAdmin;
	static LinkedList<LibraryMedia> bookList;
	//User currUser;
public:
	static void SetAdmin(bool isAdmin);
	static bool CheckIfAdmin();
	//void SetUser();
	//User GetCurrUser();
	static void LoadInventory();
	static void SaveInventory();

	static LinkedList<LibraryMedia> GetBookList();
};

