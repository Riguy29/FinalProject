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
	ISBN = new string(newISBN);
}

string& Book::GetISBN()
{
	return *ISBN;
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
	edition = newEdition;
}

int Book::GetEdition()
{
	return edition;
}

void Book::ToString()
{
	LibraryMedia::ToString();
	cout << " ISBN: " << GetISBN();
	cout << " Edition: " << GetEdition();
	cout << endl << endl;
}



Book::Book()
{
	mediaID = 1;
	title = new string("");
	mediaType = book;
	category = new string("");
	subCategory = new string("");
	inventoryCount = 0;
	price = 0;
	doner = new string("");
	this->ISBN = new string("");
	this->edition = 1;

}

Book::Book(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, 
	const string& mediaDoner, const string& bookISBN, int bookEdition) : LibraryMedia(id,mediaTitle,book,mediaPrice,mediaCat,mediaSubCat,mediaCount,mediaDoner)
{
	ISBN = new string(bookISBN);
	edition = bookEdition;
}
