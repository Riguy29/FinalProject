#pragma once
#ifndef LIBRARYMEDIA_H
#define LIBRARYMEDIA_H
#include <string>
#include <vector>
#include "Publisher.h"
#include "Author.h"
#include <random>
#include <iostream>

/*This class is the purely abstract class that acts as the parent for all other media types we have
It contains data that will be universally shared accross media such as title, authors, price, etc*/
using namespace std;

class LibraryMedia
{
public:
	enum mediaTypes
	{
		book,
		newspaper,
		conferenceJournal,
		periodical
	};

	//Accesors
	string GetTitle();
	mediaTypes GetMediaType(); //No set method since media type should never change
	double GetPrice();
	string GetCategory();
	string GetSubCategory();
	int GetInventoryCount();
	string GetDoner();
	//0 for author search string, 1 for publisher name search string, 2 for publisher address search string
	string GetSearchString(int searchParm);
	int GetMediaID(); //No set method since the id is auto generated;

	//Mutators
	void SetTitle();
	void SetMediaType(mediaTypes mediaType); //Not really sure if you should even be able to set media type
	void SetPrice();
	void SetCategory();
	void SetSubCategory();
	void SetInventoryCount();
	void SetDoner();
	void SetAuthors();
	void SetPublishers();


	//We will want to disp
	virtual void ToString();

	virtual ~LibraryMedia();
	LibraryMedia(const LibraryMedia& mediaToCopy);
	LibraryMedia();
	LibraryMedia(int id, string mediaTitle, mediaTypes typeOfMedia, double mediaPrice, string mediaCat, string mediaSubCat, int mediaCount, string mediaDoner);
protected:
	int mediaID;
	char title[50];
	mediaTypes mediaType;
	double price;
	char category[50];
	char subCategory[50];
	int inventoryCount;
	char doner[50];


};

#endif // !LIBRARYMEDIA_H