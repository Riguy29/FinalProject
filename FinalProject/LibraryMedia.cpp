#include "LibraryMedia.h"
#include "LibraryLinkedList.h"
#include "CurrentSessionInfo.h"
#ifndef LIBRARYMEDIA_CPP
#define LIBRARYMEDIA_CPP
void LibraryMedia::ToString()
{
	//cout << "MediaId: " << GetMediaID();
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

LibraryMedia::~LibraryMedia()
{
}

LibraryMedia::LibraryMedia(const LibraryMedia& mediaToCopy)
{
	mediaID = mediaToCopy.mediaID;
	title = new string(*mediaToCopy.title);
	mediaType = mediaToCopy.mediaType;
	category = new string(*mediaToCopy.category);
	subCategory = new string(*mediaToCopy.subCategory);
	price = mediaToCopy.price;
	inventoryCount = mediaToCopy.inventoryCount;
	doner = new string(*mediaToCopy.doner);
}

LibraryMedia::LibraryMedia()
{
	//mediaID = 1; //FIXME:: MIGHT want to randomly generate ids
	default_random_engine generator;
	uniform_int_distribution<int> distribution(10, 1000000);
	mediaID = distribution(generator);
	//FIXME:: Make sure it doesn't generate an already in use id
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
double LibraryMedia::GetPrice() { return price; }

int LibraryMedia::GetInventoryCount() { return inventoryCount; }
string& LibraryMedia::GetCategory() { return *category; }
string& LibraryMedia::GetSubCategory(){	return *subCategory;}
int LibraryMedia::GetMediaID(){return mediaID;}
string& LibraryMedia::GetDoner(){return *doner;}

string LibraryMedia::GetSearchString(int searchParm)
{
	string returnString = "";
	if (searchParm == 0) { //Generate Author Search String
		for (int i = 0; i < CurrentSessionInfo::authorList.size(); i++) {
			if (mediaID == CurrentSessionInfo::authorList.at(i).bookId) {
				returnString += *CurrentSessionInfo::authorList.at(i).name;
				returnString += " ";
			}
		}
		return	returnString;
	}
	else if (searchParm == 1) { //Generate PublisherName Search Parm
		for (int i = 0; i < CurrentSessionInfo::pubList.size(); i++) {
			if (mediaID == CurrentSessionInfo::pubList.at(i).GetBookId()) {
				returnString += CurrentSessionInfo::pubList.at(i).GetName();
				returnString += " ";
			}
		}
		return	returnString;
	}
	else if (searchParm == 2) { //Generate Publisher Address Search Parm
		for (int i = 0; i < CurrentSessionInfo::pubList.size(); i++) {
			if (mediaID == CurrentSessionInfo::pubList.at(i).GetBookId()) {
				returnString += CurrentSessionInfo::pubList.at(i).GetAddress();
				returnString += " ";
			}
		}
		return	returnString;
	}
	return string();
}


// Mutators
void LibraryMedia::SetInventoryCount()
{
	bool isValid = true;
	int newCount;
	do
	{
		isValid = true;
		cout << "What is the new inventory of this media?" << endl;
		cin >> newCount;
		if (newCount < 0) isValid = false; //Can't enter negative number of media
	} while (!isValid);
	inventoryCount = newCount;
	
}
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
		if (newPrice <= 0) isValid = false;
	} while (!isValid);
	price = newPrice;
}


void LibraryMedia::SetCategory()
{
	string newCat;
	bool isValid = true;
	do
	{
		isValid = true;
		cout << "Enter the category: ";
		cin >> newCat;
		// FIX ME:: Validate data
	} while (!isValid);
	category = new string(newCat);

}



void LibraryMedia::SetSubCategory()
{
	string newCat;
	bool isValid = true;
	do
	{
		isValid = true;
		cout << "Enter the Sub Category: ";
		cin >> newCat;
		// FIX ME:: Validate data
	} while (!isValid);
	category = new string(newCat);
}


void LibraryMedia::SetDoner()
{
	string newDoner;
	bool isValid = true;
	do
	{
		cout << "Enter the Doner's name: ";
		cin >> newDoner;
		// FIX ME:: Validate data
	} while (!isValid);
	category = new string(newDoner);
}
void LibraryMedia::SetAuthors()
{
	int numAuthors;
	cout << "How many authors does this media have?" << endl;
	cin >> numAuthors;

	for (int i = 0; i < numAuthors; i++)
	{
		Author tempAuthor(mediaID);
		tempAuthor.SetName();
		CurrentSessionInfo::authorList.push_back(tempAuthor);
	}
}
void LibraryMedia::SetPublishers()
{
	int numPublishers;
	cout << "How many publishers does this media have" << endl;
	cin >> numPublishers;
	for (int i = 0; i < numPublishers; i++)
	{
		Publisher tempPub(mediaID);
		tempPub.SetName();
		tempPub.SetEmail();
		tempPub.SetAddress();
	}
}
#endif // !LIBRARYMEDIA_CPP