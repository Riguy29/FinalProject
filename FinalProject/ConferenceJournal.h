#pragma once
#include "LibraryMedia.h"
#include "Date.h"
#include <string>
using namespace std;
class ConferenceJournal : public LibraryMedia
{
private:
	Date dateOfConference;
	string placeOfConference;
public:
	void SetDateOfConference(Date date);
	Date GetDateOfConference() const;

	void SetPlaceOfConference(string place);
	string GetPlaceOfConference() const;
};

