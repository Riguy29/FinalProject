#pragma once
#include "LibraryMedia.h"
#include "Date.h"
#include <string>
#include <time.h>
using namespace std;
class ConferenceJournal : public LibraryMedia
{
private:
	long dateOfConference;
	string* placeOfConference;
public:
	void ToString() override;
	void SetDateOfConference(const Date& date);
	Date& GetDateOfConference() const;

	void SetPlaceOfConference(const string& place);
	string& GetPlaceOfConference() const;

	~ConferenceJournal();
	ConferenceJournal();
	ConferenceJournal(const ConferenceJournal& copy);
	ConferenceJournal(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, const string& mediaDoner, const string& conferenceLocation, const Date& conferenceDate);
};

