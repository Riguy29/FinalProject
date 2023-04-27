#include "User.h"

// Default Constructor
User::User():firstName(new string("")), lastName(new string("")), address(new string("")), phoneNum(new string("")), email(new string("")) {}

// Overloaded Constructor
User::User(string &fName, string &lName, string &a, string &p, string &e):
	firstName(new string(fName)), lastName(new string(lName)), address(new string(a)), phoneNum(new string(p)), email(new string(e)) {}

// Destructor
User::~User() { cout << "User object destroyed: Please remove this before deployment!" << endl; }

// Accessors
string &User::getFirstName()const { return *firstName; }
string &User::getLastName()const { return *lastName; }
string &User::getAddress()const { return *address; }
string &User::getPhoneNumber()const { return *phoneNum; }
string &User::getEmail()const { return *email; }

// Mutators TODO: Implement error checking for user creation and mod
void User::setFirstName(string firstName) { this->firstName = &firstName; }
void User::setLastName(string lastName) { this->lastName = &lastName; }
void User::setAddress(string a) {}
void User::setPhoneNumber(string p) {}
void User::setEmail(string e) {}