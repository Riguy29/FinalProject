#include "FacultyMember.h"

// Default Constructor
FacultyMember::FacultyMember():User(facultyMember, "", "", "", "", ""), status(""), ID(""), password("") {}

// Overloaded Constructor
FacultyMember::FacultyMember(const char* fName, const char* lName, const char* address, 
	const char* phone, const char* email, const char* p, const char* s, const char* ID):
	User(facultyMember, fName, lName, address, phone, email), status(s), ID(ID), password(p) {}

// Copy Constructor
FacultyMember::FacultyMember(const FacultyMember& cFMem) {
	firstName = cFMem.firstName;
	lastName = cFMem.lastName;
	address = cFMem.address;
	phoneNum = cFMem.phoneNum;
	email = cFMem.email;
	status = cFMem.status;
	ID = cFMem.ID;
	password = cFMem.password;
}

// Destructor
FacultyMember::~FacultyMember() {}

// Mutators TODO: Implement Exception handling for adding and mod of FacultyMembers
void FacultyMember::setStatus(const char* s) {}
void FacultyMember::setID(const char* id) {}
void FacultyMember::setPassword(const char* p) {}

// Accessors
const char* FacultyMember::getStatus()const { return status; }
const char* FacultyMember::getID()const { return ID; }
const char* FacultyMember::getPassword()const { return password; }