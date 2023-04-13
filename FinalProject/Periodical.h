#pragma once
#include "LibraryMedia.h"
class Periodical : public LibraryMedia
{

public:
	enum publishRates {
		monthly,
		bimonthly,
		yearly,
		halfYearly
	};
	void SetPublishRate(publishRates rate);
	publishRates GetPublishRate();
private:
	publishRates publishRate;
};

