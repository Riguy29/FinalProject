#include "ConferenceJournal.h"

void ConferenceJournal::ToString()
{
	LibraryMedia::ToString();
	cout << " Place Of Confrence: " << GetPlaceOfConference();
	cout << " Date Of Confrence: " << GetDateOfConference();
	cout << endl << endl;
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
