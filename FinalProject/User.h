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
	User(bool isAdmin, bool isGuest, string status, string firstN, string lastN, string usern, string pass, int ID) {}
	User() {}
	~User() {}

	// Accessors 
	bool getIsAdmin() {}
	bool getIsGuest() {}

	string getStatusLevel() {}
	string getFirstName() {}
	string getLastName() {}
	string getUsername() {}
	string getPassword() {}

	int getUserID() {}


	// Mutators
	void setIsAdmin(bool isAdmin) {}
	void setIsGuest(bool isGuest){}
	void setStatusLevel(string statusLevel){}
	void setFirstName(string firstName) {}
	void setLastName(string lastName) {}
	void setUsername(string username){}
	void setPassword(string password){}
	void setUserID(int userID) {}
};

#endif // !USER_H