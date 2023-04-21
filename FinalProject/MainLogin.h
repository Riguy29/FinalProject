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

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Login {
private:
	User *tmpUsr;
	Date date;
	Guest guestLogin;
	InventoryScreen invScreen;
	vector<User> users;
public:
	// Constructor(s)
	Login();
	Login(Login& l);
	~Login();

	User getUser()const;
	void setUser(User u);

	// Misc functions
	static string randomPass();
	static string randomLibID();
	string isValidAddress()const;

	void loginMenu()const;
	void patronMenu()const;
	void adminMenu()const;
	void updateInfo()const;
	void myMedia()const;
	void login()const;
	void registration()const;
	void guest()const;
	void printMenu()const;

	static bool isValidName(string& name);
	static bool isLoginValid(string& inUser, string& inPass);
	static bool isEmailValid(string& email);
	static bool formatPhone(string& phone);
};

#endif // !MAINLOGIN_H
