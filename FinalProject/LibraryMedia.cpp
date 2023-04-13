#ifndef LIBRARYMEDIA_CPP
#define LIBRARYMEDIA_CPP


#include "LibraryMedia.h"
#include "LibraryLinkedList.h"
#include "Publisher.h"


void LibraryMedia::ToString()
{
	cout << "Title: " << title;
	cout << " Type: " << mediaType;
	cout << " Category: " << category;
	cout << " Sub-Category: " << subCategory;
	cout << " Inventory Amt: " << inventoryCount;
	cout << endl << endl;
	
	//FIXME add code to print authors and publishers
}

LibraryMedia::LibraryMedia()
{
	title = "";
	mediaType = book;
	category = "";
	subCategory = "";
	inventoryCount = 0;
	price = 0;
	authors = LinkedList<string>();
	publishers = LinkedList<Publisher>();
	
	
}

LibraryMedia::LibraryMedia(string title, LinkedList<string> authors, LinkedList<Publisher> publishers, mediaTypes mediaType, string cateogory, string subCategory, int inventoryCount, int price)
{
	this->title = title;
	this->authors = authors;
	this->publishers = publishers;
	this->mediaType = mediaType;
	this->category = category;
	this->subCategory = subCategory;
	this->inventoryCount = inventoryCount;
	this->price = price;
}

void LibraryMedia::SetTitle()
{
	string newTitle;
	bool isValid = true;
	do
	{
		cout << "Enter the title: ";
		cin >> newTitle;
		//FIX ME:: Validate data
	} while (!isValid);
	this->title = title;

}

string LibraryMedia::GetTitle()
{
	return title;
}

void LibraryMedia::SetMediaType(mediaTypes mediaType)
{
	this->mediaType = mediaType;
}

LibraryMedia::mediaTypes LibraryMedia::GetMediaType()
{
	return mediaType;
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

void LibraryMedia::SetPrice()
{
	double newPrice = 0;
	bool isValid = true;
	do
	{
		isValid = true; //Assume data is valid
		cout << "Enter the price: ";
		cin >> newPrice;
		//Validate data
	} while (!isValid);
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



#endif // !LIBRARYMEDIA_CPP