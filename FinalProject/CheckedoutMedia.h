#pragma once
#include "LibraryMedia.h"
#include "Date.h"
#include <chrono>
using namespace std;
class CheckedoutMedia
{
private:
	LibraryMedia media;
	double lateFee;
	Date checkoutDate;
	Date dueDate;
public:
	LibraryMedia GetMedia();
	void ReturnMedia();
};

