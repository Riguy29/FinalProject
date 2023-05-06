/*
	User.h
	This header file defines all of the User object functions.
	This also defines the following variables:
	firstName, lastName, username, password, and userID
*/

#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

class User {
public:
	// User type enum
	enum userTypes
	{
		facultyMember,
		student,
		staff
	};

	// Constructors
	User();
	User(userTypes _userType, int libID, string _firstName, string _lastName, string _address, string _phoneNum, string _email, string _password);
	User(const User& newU);
	virtual ~User();

	// Mutators
	void setFirstName();
	void setLastName();
	void setAddress();
	void setPhoneNumber();
	void setEmail();
	void setLibID(int libID);
	void setUserType(userTypes type);
	void setPassword();

	// Accessors 
	string getFirstName()const;
	string getLastName()const;
	string getAddress()const;
	string getPhoneNumber()const;
	string getEmail()const;
	int getLibID()const;
	userTypes getUserType();
	string getPassword()const;

	// Misc
	bool containsOnlyLetters(string const& str);
	void printMenu();
	virtual void printData()const;

protected:
	userTypes userType;
	char firstName[50];
	char lastName[50];
	char address[200];
	char phoneNum[50];
	char email[200];
	char password[50];
	int libID;
};

#endif // USER_H