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
	userId = copy.userId;
	bookId = copy.bookId;
	lateFee = copy.lateFee;
	checkoutDate = copy.checkoutDate;
	dueDate = copy.dueDate;
}

double CheckedoutMedia::GetFee()
{
	return 0.0;
}

string CheckedoutMedia::GetCheckoutDate()
{
	time_t timeFormmated = checkoutDate;
	struct tm timeinfo;
	char returnString[80];

	time(&timeFormmated);
	localtime_s(&timeinfo,&timeFormmated);

	strftime(returnString, 80, "%D", &timeinfo);

	return returnString;

}

string CheckedoutMedia::GetDueDate()
{
	time_t timeFormmated = dueDate;
	struct tm timeinfo;
	char returnString[80];

	time(&timeFormmated);
	localtime_s(&timeinfo, &timeFormmated);

	strftime(returnString, 80, "%D", &timeinfo);

	return returnString;
}

int CheckedoutMedia::GetUserId()
{
	return userId;
}

int CheckedoutMedia::GetBookId()
{
	return bookId;
}

void CheckedoutMedia::PrintInfo()
{
	for (LibraryMedia* media : CurrentSessionInfo::mediaList) {
		//If the media is equal to the media id for the checkout, print some info
		if (media->GetMediaID() == bookId) {
			media->ToString();
			cout << "Checked out on :" << GetCheckoutDate() << endl;
			cout << "Due on: " << GetDueDate() << endl;
			cout << "Current Fee: " << GetFee() << endl;
		}
	}
}
