#pragma once
#include "LibraryMedia.h"
class Book :public LibraryMedia
{
private:
	string ISBN;
	int edition;
public:
	void SetISBN();
	string GetISBN();
	void SetEdition();
	int GetEdition();
	Book();
	Book(string title, LinkedList<string> authors = LinkedList<string>(), LinkedList<Publisher> publishers = LinkedList<Publisher>(), mediaTypes mediaType = book, string cateogory = "", string subCategory = "", int inventoryCount = 0, double price = 0,string ISBN ="", int edition = 1);
};

