/*
	User.cpp
	This cpp file implements the User object functions, including:
	Accessors, mutators, constructors, and destructors

	This cpp file also performs all error checking within the mutator functions for object creation
*/

#include "User.h"

// Default Constructor
User::User():userType(student), firstName(""), lastName(""),
address(""), phoneNum(""), email("") {}

// Overloaded Constructor
User::User(userTypes typeOfUser, const char* fName, const char* lName, const char* a, const char* p, const char* e) {
	userType = typeOfUser;
	firstName = fName;
	lastName = lName;
	address = a;
	phoneNum = p;
	email = e;
}

// Copy Constructor
User::User(const User& cUsr) {
	userType = cUsr.userType;
	firstName = cUsr.firstName;
	lastName = cUsr.lastName;
	address = cUsr.address;
	phoneNum = cUsr.phoneNum;
	email = cUsr.email;
}

// Destructor
User::~User() { cout << "User object destroyed: Please remove this before deployment!" << endl; }

// Accessors
const char* User::getFirstName()const { return firstName; }
const char* User::getLastName()const { return lastName; }
const char* User::getAddress()const { return address; }
const char* User::getPhoneNumber()const { return phoneNum; }
const char* User::getEmail()const { return email; }
User::userTypes User::getUserType() { return userType; }

// Mutators TODO: Implement error checking for user creation and mod
void User::setFirstName(const char* firstName) { this->firstName = firstName; }
void User::setLastName(const char* lastName) { this->lastName = lastName; }
void User::setAddress(const char* a) { address = a; }
void User::setPhoneNumber(const char* p) { phoneNum = p; }
void User::setEmail(const char* e) { email = e; }
void User::setUserType(userTypes type) { userType = type; }
