/*
	This is the main login for the library.  From this screen a user will be able to choose whether they would like
	to login as a member or a guest, register as a new member, retrieve forgotten username or password or exit the system.
*/

#pragma once
#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include "GuestLogin.h"
#include "InventoryScreen.h"
#include "LibraryMedia.h"
#include "User.h"
#include "FacultyMember.h"
#include "Student.h"
#include "Staff.h"
#include "CurrentSessionInfo.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Login {
private:
	Date date;
	//GuestLogin guestLogin;
	//InventoryScreen invScreen;
	CurrentSessionInfo currSession;
	User usr;
public:
	Login();
	Login(Login& l);
	~Login();

	void printMenu();
	string getUsername()const;
	string getPassword()const;
	void setUsername(string userN);
	void setPassword(string userP);
	void login();	
	void registration();
	static bool isLoginValid(string& inUser, string& inPass);

	void userHomeMenu()const;
};

#endif // !MAINLOGIN_H
