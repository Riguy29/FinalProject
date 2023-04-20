#pragma once
#ifndef LIBRARYMEDIA_H
#define LIBRARYMEDIA_H
#include <string>
#include <vector>
#include "Publisher.h"
//#include "LibraryLinkedList.cpp"
#include <random>
#include <iostream>

/*This class is the purely abstract class that acts as the parent for all other media types we have
It contains data that will be universally shared accross media such as title, authors, price, etc*/
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
	string& GetTitle();
	void SetMediaType(mediaTypes mediaType);
	mediaTypes GetMediaType();
	void SetPrice();
	double GetPrice();
	void SetCategory();
	string& GetCategory();
	void SetSubCategory();
	string& GetSubCategory();

	void SetInventoryCount(int newCount);
	int GetInventoryCount();

	void SetDoner();
	string& GetDoner();

	//We will want to disp
	void ToString();
	LibraryMedia();
	LibraryMedia(int id, const string& mediaTitle, mediaTypes typeOfMedia, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, const string& mediaDoner);
protected:
	int mediaID;
	string* title;
	mediaTypes mediaType;
	double price;
	string* category;
	string* subCategory;
	int inventoryCount;
	string* doner;

};

#endif // !LIBRARYMEDIA_H