#ifndef LOGIN_H
#define LOGIN_H

#include "MenuScreen.h"
#include <iostream>
#include <string>
using namespace std;

class Login : public Menu {
private:
	string username;
	string password;
public:
	Login();
	Login(string username, string password);
	Login(Login& l);
	~Login();
	void print()const;
	string getUsername()const;
	string getPassword()const;
	void setUsername(string userN);
	void setPassword(string userP);
	bool isValid()const;
};

#endif // !LOGIN_H
