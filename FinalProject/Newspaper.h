#pragma once
#include "LibraryMedia.h"
class Newspaper : public LibraryMedia
{
public:
	enum PublishRate {
		daily = 0,
		weekly,
	};
	void SetPublishRate(PublishRate rate);
	PublishRate GetPublishRate();
private:
	PublishRate publishRate;
	
};