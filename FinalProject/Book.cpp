#include "Book.h"

void Book::SetISBN()
{
	string newISBN;
	bool isValid = true;
	do
	{
		cout << "Enter the ISBN: ";
		cin >> newISBN;
		//Validate data
		if (newISBN.size() != 10) isValid = false;

	} while (!isValid);
	ISBN = newISBN;
}

string Book::GetISBN()
{
	return ISBN;
}

void Book::SetEdition()
{
	int newEdition;
	bool isValid = true;
	do
	{
		cout << "Enter the Edition as an int: ";
		cin >> newEdition;

		//Validate data
		if (newEdition < 0) isValid = false;
	} while (!isValid);
	ISBN = newEdition;
}

int Book::GetEdition()
{
	return edition;
}

void Book::ToString()
{
	cout << "Title: " << title;
	cout << " Type: " << mediaType;
	cout << " ISBN: " << ISBN;
	cout << " Category: " << category;
	cout << " Sub-Category: " << subCategory;
	cout << " Inventory Amt: " << inventoryCount;
	cout << endl << endl;
}



Book::Book()
{
	title = "";
	authors = LinkedList<string>();

}

Book::Book(string title, LinkedList<string> authors, LinkedList<Publisher> publishers, mediaTypes mediaType, string category, string subCategory, int inventoryCount, double price, string ISBN, int edition)
{
	this->title = title;
	this->authors = authors;
	this->publishers = publishers;
	this->mediaType = mediaType;
	this->category = category;
	this->subCategory = subCategory;
	this->inventoryCount = inventoryCount;
	this->price = price;
	this->ISBN = ISBN;
	this->edition = edition;

}
