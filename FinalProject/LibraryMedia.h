#pragma once
#ifndef LIBRARYMEDIA_H
#define LIBRARYMEDIA_H
#include <string>
#include <vector>
#include "Publisher.h"
#include "LibraryLinkedList.cpp"

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

	void SetTitle();
	string GetTitle();
	void SetMediaType(mediaTypes mediaType);
	mediaTypes GetMediaType();
	void SetAuthors(LinkedList<string> authorList);
	LinkedList<string> GetAuthors();
	void SetPublishers(LinkedList<Publisher> publisherList);
	LinkedList<Publisher> GetPublishers();
	void SetISBN();
	string GetISBN();
	void SetPrice();
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
	LibraryMedia(string title, LinkedList<string> authors = LinkedList<string>(), LinkedList<Publisher> publishers = LinkedList<Publisher>(), mediaTypes mediaType = book, string ISBN = "", string cateogory = "", string subCategory = "", string edition = "", int inventoryCount = 0, int price = 0);
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
	string donor;

};

#endif // !LIBRARYMEDIA_H