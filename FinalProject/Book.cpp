#include "Book.h"
#include <iomanip>
void Book::SetISBN()
{
	string newISBN;
	bool isValid = true;
	do
	{
		isValid = true;
		cout << setfill(' ') << setw(54) << "Enter the ISBN: ";
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
		cout << setfill(' ') << setw(54) << "Enter the Edition as an int: ";
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

Book::~Book()
{

}



Book::Book() :LibraryMedia()
{
	mediaType = book;
	this->ISBN = new string("");
	this->edition = 1;

}

//Try to figure out a way to upcast to parent for copy constructor
Book::Book(const Book& newB) : LibraryMedia(newB)
{
	ISBN = new string(*newB.ISBN);
	edition = newB.edition;
}

Book::Book(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, 
	const string& mediaDoner, const string& bookISBN, int bookEdition) : LibraryMedia(id,mediaTitle,book,mediaPrice,mediaCat,mediaSubCat,mediaCount,mediaDoner)
{

	ISBN = new string(bookISBN);
	edition = bookEdition;
}
