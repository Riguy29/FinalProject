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

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Login {
private:
	Date date;
	Guest guestLogin;
	InventoryScreen invScreen;
	User currentUsr;
	vector<User> usrs;
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
	void guest();
	static string randomPass();
	static string randomLibID();
	static bool isValidName(string& name);
	static bool isLoginValid(string& inUser, string& inPass);
	static bool isEmailValid(string& email);
	static bool formatPhone(string& phone);
	string isValidAddress()const;

	void loginMenu()const;
	void updateInfo()const;
	void myMedia()const;
};

#endif // !MAINLOGIN_H
