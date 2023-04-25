#include "User.h"

// Default Constructor
User::User():firstName(""), lastName(""), address(""), phoneNum(""), email("") {}

// Overloaded Constructor
User::User(string fName, string lName, string a, string p, string e):
	firstName(fName), lastName(lName), address(a), phoneNum(p), email(e) {}

// Destructor
User::~User() { cout << "User object destroyed: Please remove this before deployment!" << endl; }

// Accessors
string User::getFirstName()const { return firstName; }
string User::getLastName()const { return lastName; }
string User::getAddress()const { return address; }
string User::getPhoneNumber()const { return phoneNum; }
string User::getEmail()const { return email; }

// Mutators TODO: Implement error checking for user creation and mod
void User::setFirstName(string firstName) { this->firstName = firstName; }
void User::setLastName(string lastName) { this->lastName = lastName; }
void User::setAddress(string a) {}
void User::setPhoneNumber(string p) {}
void User::setEmail(string e) {}