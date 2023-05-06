#include "CheckedoutMedia.h"

CheckedoutMedia::CheckedoutMedia()
{
	userId = -1;
	bookId = -1;
	lateFee = 0;
	checkoutDate = 0;
	dueDate = 0;
}

CheckedoutMedia::CheckedoutMedia(int IDUser, int IDbook)
{
	userId = IDUser;
	bookId = IDbook;
	lateFee = 0; //No Late fee because they just checkouted
	checkoutDate = time(0);
	dueDate = checkoutDate + 7 * 86400; //Standard checkout date is 7 days from now, converting 7 days into seconds and adding it to the checkoutDatee
}

CheckedoutMedia::~CheckedoutMedia()
{
}

CheckedoutMedia::CheckedoutMedia(const CheckedoutMedia& copy)
{
}

string CheckedoutMedia::GetCheckoutDate()
{
	string dateFormated;
	int days;
	int years;
	int months;
	return dateFormated;
}
