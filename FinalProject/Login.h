#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
using namespace std;

class Login{
private:
	string username;
	string password;
	//AdminMenu adminMenu;
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
	//bool isValid()const;
	void login()const;
	void registration()const;
	void forgot()const;
	void guest()const;
};

#endif // !LOGIN_H
