/*
	This is the main login for the library.  From this screen a user will be able to choose whether they would like
	to login as a member or a guest, register as a new member, retrieve forgotten username or password or exit the system.
*/
#pragma once
#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <iostream>
#include <string>

using namespace std;

class Login {
private:
	string username;
	string password;
public:
	Login();//default constructor
	Login(string username, string password);
	Login(Login& l);
	~Login();
	void printMenu()const;
	string getUsername()const;
	string getPassword()const;
	void setUsername(string userN);
	void setPassword(string userP);
	void login()const;
	static bool isLoginValid(string &inUser, string &inPass);
	static bool isEmailValid(string &email);
	static bool formatPhone(string &phone);
	void registration()const;
	void forgot()const;
	void guest()const;
	static string randomPass();
	static string randomLibID();
	static void TimeFunction();
	static void positionCheck(char &pos);
};

#endif // !MAINLOGIN_H
