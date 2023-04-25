#include "Student.h"

// Default constructor
Student::Student():
	User("", "", "", "", ""), status(""), ID(""), password("") {}

// Overloaded constructor
Student::Student(string fName, string lName, string address, 
	string phone, string email, string p, string s, string ID):
	User(fName, lName, address, phone, email), status(s), ID(ID), password(p) {}

// Destructor
Student::~Student() {}

// Mutators
void Student::setStatus(string s) {}
void Student::setID(string id) {}
void Student::setPassword(string p) {}

// Accessors
string Student::getStatus()const { return status; }
string Student::getID()const { return ID; }
string Student::getPassword()const { return password; }