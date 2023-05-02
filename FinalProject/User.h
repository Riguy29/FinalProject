/*
	User.h
	This header file defines all of the User object functions.
	This also defines the following variables:
	isAdmin, isGuest, statusLevel, firstName, lastName, username, password, and userID
*/

#pragma once
#ifndef USER_H
#define USER_H
#include "CurrentSessionInfo.h"

#include <iostream>
#include <iomanip>


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
	User(userTypes typeOfUsr,const char* fName, const char* lName, const char* address, const char* phoneNum, const char* email);
	User(const User& newU);
	~User();

	// Mutators
	void setFirstName();
	void setLastName();
	void setAddress();
	void setPhoneNumber();
	void setEmail();
	void setUserType(userTypes type);

	// Accessors 
	const char* getFirstName()const;
	const char* getLastName()const;
	const char* getAddress()const;
	const char* getPhoneNumber()const;
	const char* getEmail()const;
	userTypes getUserType();

	void printMenu();
protected:
	userTypes userType;
	const char* firstName;
	const char* lastName;
	const char* address;
	const char* phoneNum;
	const char* email;

public:
	// Functions to update user information
	void updateFirstName();
	void updateLastName();
	void updateAddress();
	void updatePhoneNumber();
	void updateEmail();
	void updateUserType();
	void printMenu();
	
};

#endif // USER_H