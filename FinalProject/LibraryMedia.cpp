#include "LibraryMedia.h"
#include "LibraryLinkedList.h"
#include "Publisher.h"


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
	title = "";
	mediaType = book;
	ISBN = "";
	category = "";
	subCategory = "";
	edition = "";
	inventoryCount = 0;
	price = 0;
	authors = LinkedList<string>();
	publishers = LinkedList<Publisher>();
}

LibraryMedia::LibraryMedia(string title, LinkedList<string> authors, LinkedList<Publisher> publishers, mediaTypes mediaType, string ISBN, string cateogory, string subCategory, string edition, int inventoryCount, int price)
{
	this->title = title;
	this->authors = authors;
	this->publishers = publishers;
	this->mediaType = mediaType;
	this->ISBN = ISBN;
	this->category = category;
	this->subCategory = subCategory;
	this->edition = edition;
	this->inventoryCount = inventoryCount;
	this->price = price;
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
	this->title = title;

}

void LibraryMedia::SetISBN()
{
	string newISBN;
	bool isValid = true;
	do
	{
		cout << "Enter the ISBN: ";
		cin >> newISBN;
		// FIX ME: Validate data
	} while (!isValid);
	ISBN = newISBN;
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


void LibraryMedia::SetCategory(string newCategory) { category = newCategory; }
void LibraryMedia::SetSubCategory(string newSubCategory) { subCategory = newSubCategory; }
void LibraryMedia::SetInventoryCount(int newCount) { inventoryCount = newCount; }
void LibraryMedia::SetEdition(string newEdition) { edition = newEdition; }
void LibraryMedia::SetMediaType(mediaTypes mediaType) { this->mediaType = mediaType; }
void LibraryMedia::SetAuthors(LinkedList<string> authorList) { authors = authorList; }
void LibraryMedia::SetPublishers(LinkedList<Publisher> publisherList) { publishers = publisherList; }