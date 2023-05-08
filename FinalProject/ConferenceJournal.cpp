#include "ConferenceJournal.h"

void ConferenceJournal::ToString()
{
	LibraryMedia::ToString();
	cout << " Place Of Confrence: " << GetPlaceOfConference();
	cout << " Date Of Confrence: " << GetDateOfConference();
	cout << endl << endl;
}

string ConferenceJournal::GetDateOfConference()
{
	return string();
}

string ConferenceJournal::GetPlaceOfConference()
{
	return string();
}

void ConferenceJournal::SetPlaceOfConference()
{
	string newPlace;
	bool isValid = true;
	do
	{
		try
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			isValid = true;
			cout << "Enter the Location Of the Confrence: ";
			getline(cin, newPlace);
			//Validate Data
			if (newPlace.length() > 100) throw(1);
		}
		catch (int errorCode)
		{
			system("cls");
			switch (errorCode)
			{
			case 1:
				cout << "Place is too long" << endl;
				break;
			}
			isValid = false;
		}

	} while (!isValid);
	strncpy_s(placeOfConfrence, newPlace.c_str(), sizeof(placeOfConfrence));
}

void ConferenceJournal::SetDateOfConference()
{
	string newDate;
	bool isValid = true;
	do
	{
		try
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			isValid = true;
			cout << "Enter the Date Of the Confrence: ";
			getline(cin, newDate);
			//Validate Data
			if (newDate.length() > 100) throw(1);
		}
		catch (int errorCode)
		{
			system("cls");
			switch (errorCode)
			{
			case 1:
				cout << "Date is too long" << endl;
				break;
			}
			isValid = false;
		}

	} while (!isValid);
	strncpy_s(dateOfConfrence, newDate.c_str(), sizeof(dateOfConfrence));
}

ConferenceJournal::~ConferenceJournal()
{
}

ConferenceJournal::ConferenceJournal() : LibraryMedia()
{
	strncpy_s(dateOfConfrence, "Not Set",sizeof(dateOfConfrence));
	strncpy_s(placeOfConfrence, "Not Set",sizeof(placeOfConfrence));
}

ConferenceJournal::ConferenceJournal(const ConferenceJournal& copy) : LibraryMedia(copy)
{
	strncpy_s(dateOfConfrence, copy.dateOfConfrence, sizeof(dateOfConfrence));
	strncpy_s(placeOfConfrence, copy.placeOfConfrence, sizeof(placeOfConfrence));
}

ConferenceJournal::ConferenceJournal(int id, const string mediaTitle, double mediaPrice, const string mediaCat, const string mediaSubCat, int mediaCount, string mediaDoner, string conferenceLocation, string conferenceDate)
	:LibraryMedia(id, mediaTitle, conferenceJournal, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{
	strncpy_s(dateOfConfrence, conferenceDate.c_str(), sizeof(dateOfConfrence));
	strncpy_s(placeOfConfrence, conferenceLocation.c_str(), sizeof(placeOfConfrence));
}
