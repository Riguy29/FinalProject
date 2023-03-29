#pragma once
#include <string>
#include <vector>
#include "Publisher.h"
using namespace std;
abstract class LibraryMedia
{
private:
	string Title;
	enum  mediaTypes
	{
		book,
		newspaper,
		conferenceJournal,
		periodical
	};
	mediaTypes mediaType;
	vector<string> authors;
	vector<Publisher> publishers;
	string edition;
	double price;
	string ISBN;
	string category;
	string subCategory;
	int inventoryCount;

public:


};

