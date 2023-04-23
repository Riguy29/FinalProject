#pragma once
#include "LibraryMedia.h"
class Periodical : public LibraryMedia
{

public:
	void ToString() override;
	enum PeriodicalPublishRates {
		monthly,
		bimonthly,
		yearly,
		halfYearly
	};
	void SetPublishRate(PeriodicalPublishRates rate);
	PeriodicalPublishRates GetPublishRate();

	~Periodical();
	Periodical();
	Periodical(Periodical& newP);
	Periodical(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat,
		int mediaCount, const string& mediaDoner, PeriodicalPublishRates rate);
private:
	PeriodicalPublishRates publishRate;
};

