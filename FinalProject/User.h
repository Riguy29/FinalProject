#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include "LibraryLinkedList.h"

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

	LinkedList<User> users;

public:
	// Constructors
	User(bool isAdmin, bool isGuest, string status, string firstN, string lastN, string usern, string pass, int ID, LinkedList<User> users) {}
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

	LinkedList<User> getUsers() {}

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