#include "FacultyMember.h"

// Default Constructor
FacultyMember::FacultyMember():User() {}

// Overloaded Constructor
FacultyMember::FacultyMember(string &fName, string &lName, string &address, 
	string &phone, string &email, string &p, string &s, string &ID):
	User(fName, lName, address, phone, email), status(&s), ID(&ID), password(&p) {}

// Destructor
FacultyMember::~FacultyMember() {}

// Mutators TODO: Implement Exception handling for adding and mod of FacultyMembers
void FacultyMember::setStatus(string s) {}
void FacultyMember::setID(string id) {}
void FacultyMember::setPassword(string p) {}

// Accessors
string &FacultyMember::getStatus()const { return *status; }
string &FacultyMember::getID()const { return *ID; }
string &FacultyMember::getPassword()const { return *password; }