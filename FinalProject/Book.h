#pragma once
#include "LibraryMedia.h"
class Book :public LibraryMedia
{
private:
	string* ISBN;
	int edition;
public:
	void SetISBN();
	string& GetISBN();
	void SetEdition();
	int GetEdition();
	void ToString();
	Book();
	Book(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount,
		const string& mediaDoner, const string& bookISBN, int bookEdition);
};

