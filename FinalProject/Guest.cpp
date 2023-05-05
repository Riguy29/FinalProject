#include "Guest.h"

// Default Constructor
Guest::Guest():
	User(), status("") {}

// Overloaded Constructor
Guest::Guest(string fName, string lName, string address, string phone, string email, string s):
	User(fName, lName, address, phone, email), status(s) {}

// Destructor
Guest::~Guest() {}

// Mutators
void Guest::setStatus(string s) {}

// Accessors
string Guest::getStatus()const { return status; }