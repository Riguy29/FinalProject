#include "Student.h"

// Default constructor
Student::Student():User(student, "", "", "", "", ""), status(""), ID(""), password("") {}

// Overloaded constructor
Student::Student(const char* fName, const char* lName, const char* address, 
	const char* phone, const char* email, const char* p, const char* s, const char* ID):
	User(student, fName, lName, address, phone, email), status(s), ID(ID), password(p) {}

// Copy Constructor
Student::Student(const Student& sTmp) {
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
Student::~Student() {}

// Mutators
void Student::setStatus(const char* s) {}
void Student::setID(const char* id) {}
void Student::setPassword(const char* p) {}

// Accessors
const char* Student::getStatus()const { return status; }
const char* Student::getID()const { return ID; }
const char* Student::getPassword()const { return password; }