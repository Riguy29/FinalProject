#pragma once
#ifndef LOGIN_H
#define LOGIN_H

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
	void registration()const;
	void forgot()const;
	void guest()const;
	static string randomPass();
	static string randomLibID();
};

#endif // !LOGIN_H
