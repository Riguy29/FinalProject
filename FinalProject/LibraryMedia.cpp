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
	strncpy_s(title, mediaToCopy.title,sizeof(title));
	mediaType = mediaToCopy.mediaType;
	strncpy_s(category, mediaToCopy.category, sizeof(category));
	strncpy_s(subCategory, mediaToCopy.subCategory, sizeof(subCategory));
	price = mediaToCopy.price;
	inventoryCount = mediaToCopy.inventoryCount;
	strncpy_s(doner, mediaToCopy.doner,sizeof(doner));
}

LibraryMedia::LibraryMedia()
{
	//mediaID = 1; //FIXME:: MIGHT want to randomly generate ids
	default_random_engine generator;
	uniform_int_distribution<int> distribution(10, 1000000);
	mediaID = distribution(generator);
	//FIXME:: Make sure it doesn't generate an already in use id
	strncpy_s(title, "Not Set", sizeof(title));
	mediaType = book;
	strncpy_s(category, "Not Set", sizeof(category));
	strncpy_s(subCategory, "Not Set", sizeof(subCategory));
	price = 0;
	inventoryCount = 0;
	strncpy_s(doner, "Not Set", sizeof(doner));
}

LibraryMedia::LibraryMedia(int id, string _title, mediaTypes typeOfMedia, double _price,  string _category, string _subCategory, int count, string _newDoner)
{
	mediaID = id;
	strncpy_s(title, _title.c_str(), sizeof(title));
	mediaType = typeOfMedia;
	strncpy_s(category, _category.c_str(), sizeof(category));
	strncpy_s(subCategory, _subCategory.c_str() , sizeof(subCategory));
	price = _price;
	inventoryCount = count;
	strncpy_s(doner, _newDoner.c_str(), sizeof(doner));
}

// Accessors

LibraryMedia::mediaTypes LibraryMedia::GetMediaType() { return mediaType; }
double LibraryMedia::GetPrice() { return price; }

int LibraryMedia::GetInventoryCount() { return inventoryCount; }
string LibraryMedia::GetCategory() { return category; }
string LibraryMedia::GetSubCategory(){	return subCategory;}
int LibraryMedia::GetMediaID(){return mediaID;}
string LibraryMedia::GetDoner(){return doner;}

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
	strncpy_s(title, newTitle.c_str(), sizeof(title));

}

string LibraryMedia::GetTitle()
{
	return title;
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
	strncpy_s(category,newCat.c_str(), sizeof(category));

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
	strncpy_s(category, newCat.c_str(), sizeof(category));
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
	strncpy_s(doner, newDoner.c_str(), sizeof(doner));
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
		CurrentSessionInfo::pubList.push_back(tempPub);
	}
}
#endif // !LIBRARYMEDIA_CPP