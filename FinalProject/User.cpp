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

// Destructor
User::~User() { cout << "User object destroyed: Please remove this before deployment!" << endl; }

// Accessors
bool User::getIsAdmin() { return this->isAdmin; }
bool User::getIsGuest() { return this->isGuest; }

string User::getStatusLevel() { return this->statusLevel; }
string User::getFirstName() { return this->firstName; }
string User::getLastName() { return this->lastName; }
string User::getUsername() { return this->username; }
string User::getPassword() { return this->password; }

int User::getUserID() { return this->userID; }

// Mutators
void User::setIsAdmin(bool isAdmin) { this->isAdmin = isAdmin; }
void User::setIsGuest(bool isGuest) { this->isGuest = isGuest; }
void User::setStatusLevel(string statusLevel) { this->statusLevel = statusLevel; }
void User::setFirstName(string firstName) { this->firstName = firstName; }
void User::setLastName(string lastName) { this->lastName = lastName; }
void User::setUsername(string username) { this->username = username; }
void User::setPassword(string password) { this->password = password; }
