#pragma once
#include "LibraryMedia.h"
class Book :public LibraryMedia
{
private:
	char ISBN[11]; //Only have it set to be 10 + /0 because an ISBN can only be 10 characters
	int edition;
public:
	void SetISBN();
	string GetISBN();
	void SetEdition();
	int GetEdition();

	void ToString() override;
	~Book();
	Book();
	Book(const Book& newB);
	Book(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount,
		const string& mediaDoner, const string& bookISBN, int bookEdition);
};

