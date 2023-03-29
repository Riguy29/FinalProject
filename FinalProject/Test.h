#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cassert>


using namespace std;

class BookList {
private:
	string bTitle;
	string bAuthor;
	string bPub;
	unsigned int bEdition;
	unsigned long bISBN;
	string bPubAddress;
	string bPubEmail;
	double bPrice;
public:
	//BookList::BookList();
	BookList(string bTitle, string bAuthor, string bPub,
		unsigned int bEdition, unsigned long bISBN, string bPubAddress,
		string bPubEmail, double bPrice);
	~BookList();
	void setTitle(string bTitle);
	void setAuthor(string bAuthor);
	void setPub(string bPub);
	void setEdition(int bEdition);
	void setISBN(long bISBN);
	void setPubAddress(string bPubAddress);
	void setubEmail(string bPubEmail);
	void setPrice(double bPrice);
	string getTitle()const;
	string getAuthor()const;
	string getPub()const;
	unsigned int getEdition()const;
	unsigned long getISBN()const;
	string getPubAddress()const;
	string getPubEmail()const;
	double getPrice()const;
	void printBookList()const;

};



#endif // !TEST_H
