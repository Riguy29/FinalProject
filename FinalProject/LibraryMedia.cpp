#include "LibraryMedia.h"

void LibraryMedia::ToString()
{
	cout << "Title: " << title;
	cout << " Type: " << mediaType;
	cout << " ISBN: " << ISBN;
	cout << " Category: " << category;
	cout << " Sub-Category: " << subCategory;
	cout << " Edition: " << edition;
	cout << " Inventory Amt: " << inventoryCount;
	cout << endl << endl;
	
	//FIXME add code to print authors and publishers
}

LibraryMedia::LibraryMedia()
{

}

void LibraryMedia::SetTitle(string newTitle)
{
}

string LibraryMedia::GetTitle()
{
	return string();
}

void LibraryMedia::SetAuthors(LinkedList<string> authorList)
{
	authors = authorList;
}

LinkedList<string> LibraryMedia::GetAuthors()
{
	return authors;
}

void LibraryMedia::SetPublishers(LinkedList<Publisher> publisherList)
{
	publishers = publisherList;
}

LinkedList<Publisher> LibraryMedia::GetPublishers()
{
	return LinkedList<Publisher>();
}

void LibraryMedia::SetISBN(string newISBN)
{
	ISBN = newISBN;
}

string LibraryMedia::GetISBN()
{
	return ISBN;
}

void LibraryMedia::SetPrice(int newPrice)
{
	price = newPrice;
}

double LibraryMedia::GetPrice()
{
	return price;
}

void LibraryMedia::SetCategory(string newCategory)
{
	category = newCategory;
}

string LibraryMedia::GetCategory()
{
	return category;
}

void LibraryMedia::SetSubCategory(string newSubCategory)
{
	subCategory = newSubCategory;
}

string LibraryMedia::GetSubCategory()
{
	return subCategory;
}

void LibraryMedia::SetInventoryCount(int newCount)
{
	inventoryCount = newCount;
}

int LibraryMedia::GetInventoryCount()
{
	return inventoryCount;
}

void LibraryMedia::SetEdition(string newEdition)
{
	edition = newEdition;
}

string LibraryMedia::GetEdition()
{
	return edition;
}
