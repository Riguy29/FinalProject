#include "Book.h"

void Book::SetISBN()
{
	string newISBN;
	bool isValid = true;
	do
	{
		try
		{
			isValid = true;
			cout << "Enter the ISBN: ";
			cin >> newISBN;
			if (newISBN.length() != 10) throw(1);
			for (char stringChar : newISBN) {
				if (isalpha(stringChar)) {
					throw(2);
				}
			}
		}
		catch (int errorCode)
		{
			system("cls");
			switch (errorCode)
			{
			case 1:
				cout << "ISBN must be exactly 10 digits long" << endl;
				break;
			case 2:
				cout << "ISBN must only contain numbers" << endl;
			default:
				break;
			}
			isValid = false;
		}

	} while (!isValid);
	strncpy_s(ISBN, newISBN.c_str(), sizeof(ISBN));
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

Book::~Book() {}

Book::Book() :LibraryMedia()
{
	mediaType = book;
	strncpy_s(ISBN,"Not Set", sizeof(ISBN));
	this->edition = 1;

}

//Try to figure out a way to upcast to parent for copy constructor
Book::Book(const Book& newB) : LibraryMedia(newB)
{
	strncpy_s(ISBN, newB.ISBN, sizeof(ISBN));
	edition = newB.edition;
}

Book::Book(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, 
	const string& mediaDoner, const string& bookISBN, int bookEdition) : LibraryMedia(id,mediaTitle,book,mediaPrice,mediaCat,mediaSubCat,mediaCount,mediaDoner)
{

	strncpy_s(ISBN, bookISBN.c_str(), sizeof(ISBN));
	edition = bookEdition;
}
