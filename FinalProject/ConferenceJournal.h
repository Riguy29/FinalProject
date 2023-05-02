#pragma once
#include "LibraryMedia.h"
#include "Date.h"
#include <string>
#include <time.h>
using namespace std;
class ConferenceJournal : public LibraryMedia
{
private:
	char dateOfConfrence[100];
	char placeOfConfrence[100];
public:
	void ToString() override;

	//Accessors
	string GetDateOfConference();
	string GetPlaceOfConference();
	//Mutators
	void SetPlaceOfConference();
	void SetDateOfConference();


	~ConferenceJournal();
	ConferenceJournal();
	ConferenceJournal(const ConferenceJournal& copy);
	ConferenceJournal(int id, string mediaTitle, double mediaPrice, string mediaCat, string mediaSubCat, int mediaCount, string mediaDoner, string conferenceLocation, string conferenceDate);
};

