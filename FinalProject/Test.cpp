#ifndef TEST_CPP
#define TEST_CPP
#include "Test.h"

/*
BookList::BookList() {
	bTitle = "";
	bAuthor = "";
	bPub = "";
	bEdition = "";
	bISBN = 0000000000;
	bPubAddress = "";
	bPubEmail = "";
	bPrice = 0.0;
}
*/
BookList::BookList(string title, string author, string pub,
	unsigned int edition, unsigned long ISBN, string pubAddress,
	string pubEmail, double price)
	:bTitle(title), bAuthor(author), bPub(pub), bEdition(edition), bISBN(ISBN),
	bPubAddress(pubAddress), bPubEmail(pubEmail), bPrice(price) {

}

BookList::~BookList() {

}
void BookList::setTitle(string title) { bTitle = title; }
void BookList::setAuthor(string author) { bAuthor = author; }
void BookList::setPub(string pub) { bPub = pub; }
void BookList::setEdition(int edition) { bEdition = edition; }
void BookList::setISBN(long ISBN) { bISBN = ISBN; }
void BookList::setPubAddress(string pubAddress) { bPubAddress = pubAddress; }
void BookList::setubEmail(string pubEmail) { bPubEmail = pubEmail; }
void BookList::setPrice(double price) { bPrice = price; }
string BookList::getTitle()const { return bTitle; }
string BookList::getAuthor()const { return bAuthor; }
string BookList::getPub()const { return bPub; }
unsigned int BookList::getEdition()const { return bEdition; }
unsigned long BookList::getISBN()const { return bISBN; }
string BookList::getPubAddress()const { return bPubAddress; }
string BookList::getPubEmail()const { return bPubEmail; }
double BookList::getPrice()const { return bPrice; }
void BookList::printBookList()const {
	//for(int i = 0; i < size(); )
	//cout <<  
}
#endif