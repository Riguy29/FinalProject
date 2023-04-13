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
	void SetPrice();
	double GetPrice();
	void SetCategory(string newCategory);
	string GetCategory();
	void SetSubCategory(string newSubCategory);
	string GetSubCategory();

	void SetInventoryCount(int newCount);
	int GetInventoryCount();

	void ToString();

	LibraryMedia();
	LibraryMedia(string title, LinkedList<string> authors = LinkedList<string>(), LinkedList<Publisher> publishers = LinkedList<Publisher>(), mediaTypes mediaType = book, string cateogory = "", string subCategory = "", int inventoryCount = 0, int price = 0);
protected:
	string title;
	mediaTypes mediaType;
	LinkedList<Publisher> publishers;
	LinkedList<string> authors;
	double price;
	string category;
	string subCategory;
	int inventoryCount;
	string doner;

};

#endif // !LIBRARYMEDIA_H