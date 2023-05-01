#include "Staff.h"

// Default constructor
Staff::Staff():User(staff, "", "", "", "", ""), status(""), ID(""), password("") {}

// Overloaded constructor
Staff::Staff(const char* fName, const char* lName, const char* address, 
	const char* phone, const char* email, const char* p, const char* s, const char* ID):
	User(staff, fName, lName, address, phone, email), status(s), ID(ID), password(p) {}

// Copy Constructor
Staff::Staff(const Staff& sTmp) {
	firstName = sTmp.firstName;
	lastName = sTmp.lastName;
	address = sTmp.address;
	phoneNum = sTmp.phoneNum;
	email = sTmp.email;
	status = sTmp.status;
	ID = sTmp.ID;
	password = sTmp.password;
}

// Destructor
Staff::~Staff() {}

// Mutators
void Staff::setStatus(const char* s) {}
void Staff::setID(const char* id) {}
void Staff::setPassword(const char* p) {}

// Accessors
const char* Staff::getStatus()const { return status; }
const char* Staff::getID()const { return ID; }
const char* Staff::getPassword()const { return password; }