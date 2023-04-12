/*
* FinalProject.cpp
* 
* Main source file for the project. Includes the main function.
* Also includes the time function to get the current date and time for the program.
*/

#include "FinalProject.h"

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
	Login login;
	login.printMenu();

	//opeing current user in order to open the correct menu
	string line;
	ifstream currUser("currentUser.txt");
	if (currUser.is_open()) {
		getline(currUser, line);
		if (line.at(0) == 'M') {
			AdminMenu adminMenu;
			adminMenu.printMenu();
			CurrentSessionInfo::SetAdmin(true);
		}
		else if (line.at(0) == 'E' || line.at(0) == 'S')
			cout << "Menu Under Construction";
		currUser.close();
	}

	return 0;
}