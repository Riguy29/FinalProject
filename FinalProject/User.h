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
	void setIsAdmin(bool isAdmin)const {}
	void setIsGuest(bool isGuest)const {}
	void setStatusLevel(string statusLevel)const {}
	void setFirstName(string firstName)const {}
	void setLastName(string lastName)const {}
	void setUsername(string username)const {}
	void setPassword(string password)const {}
	void setUserID(int userID)const {}
};

#endif // !USER_H