#include "ConferenceJournal.h"

ConferenceJournal::~ConferenceJournal()
{
}

ConferenceJournal::ConferenceJournal() : LibraryMedia()
{

}

ConferenceJournal::ConferenceJournal(const ConferenceJournal& copy) : LibraryMedia(copy)
{
	dateOfConference = copy.dateOfConference;
	placeOfConference = copy.placeOfConference;
}

ConferenceJournal::ConferenceJournal(int id, const string& mediaTitle, mediaTypes typeOfMedia, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, const string& mediaDoner, const string& conferenceLocation, const Date& conferenceDate)
	:LibraryMedia(id, mediaTitle, conferenceJournal, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{

}
