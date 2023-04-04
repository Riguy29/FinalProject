#pragma once
#include <string>
#include <vector>
#include "Publisher.h"
#include "LibraryLinkedList.h"
using namespace std;
class LibraryMedia
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
	LinkedList<Publisher> publishers;
	LinkedList<string> authors;
	string edition;
	double price;
	string ISBN;
	string category;
	string subCategory;
	int inventoryCount;

public:
	void SetAuthors(LinkedList<string> authorList);
	void SetPublishers(LinkedList<Publisher> publisherList);
	void SetISBN(string newISBN);
	string GetISBN();
	void SetPrice(int newPrice);
	double GetPrice();


	void ToString();


};

