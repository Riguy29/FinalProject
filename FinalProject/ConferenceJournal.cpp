#include "ConferenceJournal.h"

void ConferenceJournal::ToString()
{
}

ConferenceJournal::~ConferenceJournal()
{
}

ConferenceJournal::ConferenceJournal() : LibraryMedia()
{
	placeOfConference = new string("");
	dateOfConference = 0; // Jan 1st 1970
}

ConferenceJournal::ConferenceJournal(const ConferenceJournal& copy) : LibraryMedia(copy)
{
	dateOfConference = copy.dateOfConference;
	placeOfConference = copy.placeOfConference;
}

ConferenceJournal::ConferenceJournal(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, const string& mediaDoner, const string& conferenceLocation, const Date& conferenceDate)
	:LibraryMedia(id, mediaTitle, conferenceJournal, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{
	placeOfConference = new string(conferenceLocation);
	long DateInSeconds = 0;
	tm dateToConvert;
}
