
#include "LibraryLinkedList.h"
#include "Test.h"
#include "Login.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
//#include <stdlib.h>

using namespace std;

void TimeFunction() {
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	//cout << "The local date and time is: " << dt << endl;

	// convert now to tm struct for UTC
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	//cout << "The date and time is: " << dt << endl;
	cout << dt << endl;
}

int main()
{
	TimeFunction();
	Login login;
	login.printMenu();

	return 0;
}