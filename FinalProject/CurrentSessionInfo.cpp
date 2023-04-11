#include "CurrentSessionInfo.h"


//I guess because this is a static variable we have to define it outside of our .h file, idk thats what the internet told me and now it works so
bool CurrentSessionInfo::isUserAdmin = false;
LinkedList<LibraryMedia> CurrentSessionInfo::bookList = LinkedList<LibraryMedia>();

void CurrentSessionInfo::SetAdmin(bool isAdmin)
{
	isUserAdmin = isAdmin;
}

bool CurrentSessionInfo::CheckIfAdmin()
{
	return isUserAdmin;
}

void CurrentSessionInfo::LoadInventory()
{
	XMLDocument inventoryXML;
	inventoryXML.LoadFile("InventoryRecord.xml");
	//Gets the first book in our books section
	XMLElement* currBook = inventoryXML.RootElement()->FirstChildElement("inventory")->FirstChildElement("books")->FirstChildElement("book");

	while (currBook != nullptr)
	{
		string newTitle = currBook->FirstChildElement("title")->GetText();
		//cout << newTitle;
		LibraryMedia newBook(
			newTitle
		);

		bookList.insertItem(newBook);
		//cout << newBook.GetTitle() << endl;
		currBook = currBook->NextSiblingElement();
	}
	//cout << bookList.size() << endl;
	Node<LibraryMedia>* book = bookList.GetHead();
	if (book == NULL) cout << "NULL";
	cout << book->data.GetTitle() << endl;

	
}

LinkedList<LibraryMedia> CurrentSessionInfo::GetBookList()
{
	return bookList;
}
