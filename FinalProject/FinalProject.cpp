
#include "LibraryLinkedList.h"
#include "Test.h"
#include "Login.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

void TimeFunction() {
	// current date/time based on current system
	time_t now = time(0);

	// Char array for ctime_s to get time to compile properly using C++ 20
	// This char array holds the string of what the current time is
	char str[26];

	// Get the current time and convert to string, storing it in the str char array
	ctime_s(str, sizeof str, &now);

	cout << "The local date and time is: " << str << endl;
}

int main()
{
	TimeFunction();
	Login login;
	login.printMenu();

	return 0;
}