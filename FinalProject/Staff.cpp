#include "Staff.h"

// Default constructor
Staff::Staff():
	User("", "", "", "", ""), status(""), ID(""), password("") {}

// Overloaded constructor
Staff::Staff(string fName, string lName, string address, 
	string phone, string email, string p, string s, string ID):
	User(fName, lName, address, phone, email), status(s), ID(ID), password(p) {}

// Destructor
Staff::~Staff() {}

// Mutators
void Staff::setStatus(string s) {}
void Staff::setID(string id) {}
void Staff::setPassword(string p) {}

// Accessors
string Staff::getStatus()const { return status; }
string Staff::getID()const { return ID; }
string Staff::getPassword()const { return password; }