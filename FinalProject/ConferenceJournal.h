#pragma once
#include "LibraryMedia.h"
#include "Date.h"
#include <string>
class ConferenceJournal : public LibraryMedia
{
private:
	Date dateOfConference;
	string placeOfConference;

};

