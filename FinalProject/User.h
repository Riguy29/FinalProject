/*
	User.h
	This header file defines all of the User object functions.
	This also defines the following variables:
	isAdmin, isGuest, statusLevel, firstName, lastName, username, password, and userID
*/

#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
private:
	bool isAdmin;
	bool isGuest;

	string statusLevel;
	string firstName;
	string lastName;
	string username;
	string password;
	
	int userID;

public:
	// Constructors
	User(bool isAdmin, bool isGuest, string status, string firstN, string lastN, string usern, string pass, int ID);
	User();
	User(User& u);
	~User();

	// Accessors 
	bool getIsAdmin()const;
	bool getIsGuest()const;

	string getStatusLevel()const;
	string getFirstName()const;
	string getLastName()const;
	string getUsername()const;
	string getPassword()const;

	int getUserID()const;

	// Mutators
	void setIsAdmin(bool isAdmin);
	void setIsGuest(bool isGuest);
	void setStatusLevel(string statusLevel);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setUsername(string username);
	void setPassword(string password);
	void setUserID(int userID);
};

#endif // !USER_H