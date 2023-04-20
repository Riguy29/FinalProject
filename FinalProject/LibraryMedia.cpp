#include "LibraryMedia.h"
#include "LibraryLinkedList.h"
#include "CurrentSessionInfo.h"

void LibraryMedia::ToString()
{
	cout << "MediaId: " << mediaID;
	cout << " Title: " << GetTitle();
	cout << " Type: ";

	switch (mediaType)
	{
	case LibraryMedia::book:
		cout << "Book";
		break;
	case LibraryMedia::newspaper:
		cout << "Newspaper";
		break;
	case LibraryMedia::conferenceJournal:
		cout << "Conference Journal";
		break;
	case LibraryMedia::periodical:
		cout << "Periodical";
		break;
	default:
		break;
	}
	cout << " Category: " << GetCategory();
	cout << " Authors: ";

	//Access our static author list, and search the list for any authors that match our book id
	for (int i = 0; i < CurrentSessionInfo::authorList.size(); i++) {
		if (mediaID == CurrentSessionInfo::authorList.at(i).bookId) {
			cout << *CurrentSessionInfo::authorList.at(i).name;
		}
	}

	cout << " Publishers: ";
	for (int i = 0; i < CurrentSessionInfo::pubList.size(); i++) {
		if (mediaID == CurrentSessionInfo::pubList.at(i).GetBookId()) {
			cout << CurrentSessionInfo::pubList.at(i).GetName();
		}
	}
	cout << " Sub-Category: " << GetSubCategory();
	cout << " Inventory Amt: " << inventoryCount;
	cout << " Price: " << price;
	cout << " Donated By: " << GetDoner();
	//cout << endl << endl;
}

LibraryMedia::LibraryMedia()
{
	mediaID = 1;
	title = new string("");
	mediaType = book;
	category = new string("");
	subCategory = new string("");
	inventoryCount = 0;
	price = 0;
	doner = new string("");
}

LibraryMedia::LibraryMedia(int id, const string& _title, mediaTypes typeOfMedia, double _price, const string& _category, const string& _subCategory, int count, const string& _newDoner)
{
	mediaID = id;
	title = new string(_title);
	mediaType = typeOfMedia;
	price = _price;
	category = new string(_category);
	subCategory = new string(_subCategory);
	inventoryCount = count;
	doner = new string(_newDoner);
}

// Accessors

LibraryMedia::mediaTypes LibraryMedia::GetMediaType() { return mediaType; }
LinkedList<string> LibraryMedia::GetAuthors() { return authors; }
LinkedList<Publisher> LibraryMedia::GetPublishers() { return LinkedList<Publisher>(); }
string LibraryMedia::GetISBN() { return ISBN; }
double LibraryMedia::GetPrice() { return price; }
string LibraryMedia::GetCategory() { return category; }
string LibraryMedia::GetSubCategory() { return subCategory; }
int LibraryMedia::GetInventoryCount() { return inventoryCount; }
string LibraryMedia::GetEdition() { return edition; }

// Mutators

void LibraryMedia::SetTitle()
{
	string newTitle;
	bool isValid = true;
	do
	{
		cout << "Enter the title: ";
		cin >> newTitle;
		// FIX ME:: Validate data
	} while (!isValid);
	title = new string(newTitle);

}

string& LibraryMedia::GetTitle()
{
	return *title;
}

void LibraryMedia::SetMediaType(mediaTypes mediaType)
{
	this->mediaType = mediaType;
}

LibraryMedia::mediaTypes LibraryMedia::GetMediaType()
{
	return mediaType;
}

void LibraryMedia::SetPrice()
{
	double newPrice = 0;
	bool isValid = true;
	do
	{
		isValid = true; // Assume data is valid
		cout << "Enter the price: ";
		cin >> newPrice;
		// FIX ME: Validate data
	} while (!isValid);
	price = newPrice;
}


void LibraryMedia::SetCategory()
{
	//FINISH ME
}

string& LibraryMedia::GetCategory()
{
	return *category;
}

void LibraryMedia::SetSubCategory()
{
}

string& LibraryMedia::GetSubCategory()
{
	return *subCategory;
}

void LibraryMedia::SetInventoryCount(int newCount)
{
	inventoryCount = newCount;
}

int LibraryMedia::GetInventoryCount()
{
	return inventoryCount;
}

void LibraryMedia::SetDoner()
{
}

string& LibraryMedia::GetDoner()
{
	return *doner;
}



#endif // !LIBRARYMEDIA_CPP