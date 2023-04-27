#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
protected:
	string* firstName;
	string* lastName;
	string* address;
	string* phoneNum;
	string* email;
public:
	// Constructors
	User(string &fName, string &lName, string &address, string &phoneNum, string &email) {}
	User() {}
	~User() {}
	User(const User& newU);

	// Mutators
	void setFirstName(string firstName) {}
	void setLastName(string lastName) {}
	void setAddress(string a) {}
	void setPhoneNumber(string p) {}
	void setEmail(string e) {}

	// Accessors 
	string &getFirstName()const {}
	string &getLastName()const {}
	string &getAddress()const {}
	string &getPhoneNumber()const {}
	string &getEmail()const {}
};

#endif // USER_H