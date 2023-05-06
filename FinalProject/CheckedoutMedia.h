#pragma once
#include "LibraryMedia.h"
#include <chrono>
/*This class will be used to keep track of media that users have checked out
It holds references to the both the id of the user that checked it out and the id of the book that was checked out*/
using namespace std;
class CheckedoutMedia
{
private:
	int userId;
	int bookId;
	double lateFee;
	long checkoutDate; //Both are stored as seconds since 1970
	long dueDate; 
public:
	//Constructors
	CheckedoutMedia();
	CheckedoutMedia(int IDUser, int IDbook); //This constructor is going to be used when a user checks out a book
	~CheckedoutMedia();
	CheckedoutMedia(const CheckedoutMedia& copy);


	//Accessors 
	double GetFee(); //Calulate Late fee when the get function is called
	string GetCheckoutDate(); //Convert the seconds from 1970 into a string
	string GetDueDate();

	//No Mutators because everything is auto generated

	//Methods
	void Renew();
	void ReturnMedia();

};

