#pragma once
#include <chrono>
using namespace std;
using namespace chrono;
class Date
{
private:
	day d;
	month m;
	year y;
public:
	string GetDate();

};

