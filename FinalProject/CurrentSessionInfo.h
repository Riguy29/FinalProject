#pragma once

#include "LibraryLinkedList.h"
#include "LibraryMedia.h"

class CurrentSessionInfo
{
private:
	static bool isUserAdmin;
	static LinkedList<LibraryMedia> bookList;
public:
	static void SetAdmin(bool isAdmin);
	static bool CheckIfAdmin();
	static void LoadInventory();
	static void SaveInventory();

	static LinkedList<LibraryMedia> GetBookList();
};

