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
	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);
	void setAddress(const char* a);
	void setPhoneNumber(const char* p);
	void setEmail(const char* e);
	void setUserType(userTypes type);

	// Accessors 
	const char* getFirstName()const;
	const char* getLastName()const;
	const char* getAddress()const;
	const char* getPhoneNumber()const;
	const char* getEmail()const;
	userTypes getUserType();
	bool getAdminStatus() const {};

protected:
	userTypes userType;
	const char* firstName;
	const char* lastName;
	const char* address;
	const char* phoneNum;
	const char* email;

public:
	// Functions to update user information
	void updateFirstName()const;
	void updateLastName()const;
	void updateAddress()const;
	void updatePhoneNumber()const;
	void updateEmail()const;
	void updateUserType()const;
	void printMenu()const;
	
};

#endif // USER_H