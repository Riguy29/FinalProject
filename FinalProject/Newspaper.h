#pragma once
#include "LibraryMedia.h"
class Newspaper : public LibraryMedia
{
public:
	void ToString();
	enum NewspaperPublishRates {
		daily = 0,
		weekly,
	};
	void SetPublishRate();
	NewspaperPublishRates GetPublishRate();

	virtual ~Newspaper();
	Newspaper();
	Newspaper(Newspaper& copy);
	Newspaper(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount,
		const string& mediaDoner, NewspaperPublishRates newspaperPublishRate);
private:
	NewspaperPublishRates publishRate;
	
};