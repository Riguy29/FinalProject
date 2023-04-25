#include "Periodical.h"

void Periodical::ToString()
{
	LibraryMedia::ToString();
	cout << " Publish Rate: ";
	switch (publishRate)
	{
	case Periodical::monthly:
		cout << "Monthly";
		break;
	case Periodical::bimonthly:
		cout << "BiMontly";
		break;
	case Periodical::yearly:
		cout << "Yearly";
		break;
	case Periodical::halfYearly:
		cout << "Half Yearly";
		break;
	default:
		break;
	}
}

void Periodical::SetPublishRate()
{
}

Periodical::PeriodicalPublishRates Periodical::GetPublishRate()
{
	return PeriodicalPublishRates();
}

Periodical::~Periodical()
{
}

Periodical::Periodical() : LibraryMedia()
{
	publishRate = monthly;
}

Periodical::Periodical(Periodical& newP) : LibraryMedia(newP)
{
	publishRate = newP.publishRate;
}

Periodical::Periodical(int id, const string& mediaTitle, double mediaPrice, const string& mediaCat, const string& mediaSubCat, int mediaCount, const string& mediaDoner, PeriodicalPublishRates rate) 
	: LibraryMedia(id, mediaTitle, periodical, mediaPrice, mediaCat, mediaSubCat, mediaCount, mediaDoner)
{
	publishRate = rate;
}
