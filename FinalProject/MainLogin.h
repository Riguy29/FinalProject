/*
	This is the main login for the library.  From this screen a user will be able to choose whether they would like
	to login as a member or a guest, register as a new member, retrieve forgotten username or password or exit the system.
*/
#ifndef MAINLOGIN_H
#define MAINLOGIN_H
#include "GuestLogin.h"
#include "InventoryScreen.h"

#include <iostream>
#include <string>

using namespace std;

class Login {
private:
	//User tempUser;
	Date date;
	Guest guestLogin;
	InventoryScreen invScreen;
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
	void registration()const;
	void guest()const;
	static string randomPass();
	static string randomLibID();
	static void TimeFunction();
	static bool isValidName(string& name);
	static bool isLoginValid(string& inUser, string& inPass);
	static bool isEmailValid(string& email);
	static bool formatPhone(string& phone);
	string isValidAddress()const;
	//void borrow()const;
	//void placeHold()const;
	//void renew()const;
	//void checkout()const;
	//void returnBook()const;
	void patronMenu()const;
	void adminMenu()const;
	void updateInfo()const;
	void myMedia()const;
	
};

#endif // !MAINLOGIN_H
