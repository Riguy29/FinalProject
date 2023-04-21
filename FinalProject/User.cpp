/*
	User.cpp
	This cpp file implements the User object functions, including:
	Accessors, mutators, constructors, and destructors

	This cpp file also performs all error checking within the mutator functions for object creation
*/

#include "User.h"

// Constructors
User::User() {
	isAdmin = false;
	isGuest = true;

	statusLevel = "";
	firstName = "";
	lastName = "";
	username = "";
	password = "";

	userID = 0;
}

User::User(bool isAdmin, bool isGuest, string status, string firstN, string lastN, string usern, string pass, int ID) {
	this->isAdmin = isAdmin;
	this->isGuest = isGuest;
	this->statusLevel = status;
	this->firstName = firstN;
	this->lastName = lastName;
	this->username = usern;
	this->password = pass;
	this->userID = ID;
}

// Copy constructor
User::User(User& u):isAdmin(u.isAdmin), isGuest(u.isGuest), statusLevel(u.statusLevel), 
	firstName(u.firstName), lastName(u.lastName), username(u.username), password(u.password),
	userID(u.userID) {}

// Destructor
User::~User() { cout << "User object destroyed: Please remove this before deployment!" << endl; }

// Accessors
bool User::getIsAdmin()const { return this->isAdmin; }
bool User::getIsGuest()const { return this->isGuest; }

string User::getStatusLevel()const { return this->statusLevel; }
string User::getFirstName()const { return this->firstName; }
string User::getLastName()const { return this->lastName; }
string User::getUsername()const { return this->username; }
string User::getPassword()const { return this->password; }

int User::getUserID()const { return this->userID; }

// Mutators
// TODO: Add error checking for passed in data
void User::setIsAdmin(bool isAdmin) { this->isAdmin = isAdmin; }
void User::setIsGuest(bool isGuest) { this->isGuest = isGuest; }
void User::setStatusLevel(string statusLevel) { this->statusLevel = statusLevel; }
void User::setFirstName(string firstName) { this->firstName = firstName; }
void User::setLastName(string lastName) { this->lastName = lastName; }
void User::setUsername(string username) { this->username = username; }
void User::setPassword(string password) { this->password = password; }
void User::setUserID(int ID) { this->userID = ID; }

