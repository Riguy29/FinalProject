#pragma once
#ifndef LIBRARYMEDIA_H
#define LIBRARYMEDIA_H
#include <string>
#include <vector>
#include "Publisher.h"
#include "LibraryLinkedList.h"

using namespace std;

class LibraryMedia
{
public:
	enum  mediaTypes
	{
		book,
		newspaper,
		conferenceJournal,
		periodical
	};

	void SetTitle(string newTitle);
	string GetTitle();
	void SetMediaType(mediaTypes mediaType);
	mediaTypes GetMediaType();
	void SetAuthors(LinkedList<string> authorList);
	LinkedList<string> GetAuthors();
	void SetPublishers(LinkedList<Publisher> publisherList);
	LinkedList<Publisher> GetPublishers();
	void SetISBN(string newISBN);
	string GetISBN();
	void SetPrice(int newPrice);
	double GetPrice();
	void SetCategory(string newCategory);
	string GetCategory();
	void SetSubCategory(string newSubCategory);
	string GetSubCategory();

	void SetInventoryCount(int newCount);
	int GetInventoryCount();

	void SetEdition(string newEdition);
	string GetEdition();

	void ToString();

	LibraryMedia();
private:
	string title;

	mediaTypes mediaType;
	LinkedList<Publisher> publishers;
	LinkedList<string> authors;
	string edition;
	double price;
	string ISBN;
	string category;
	string subCategory;
	int inventoryCount;

};

#endif // !LIBRARYMEDIA_H