#ifndef STAFF_H
#define STAFF_H
#include "User.h"

class Staff : User {
protected:
	string *status;
	string *ID;
	string *password;
public:
	Staff(string &fName, string &lName, string &address, string &phone, 
		string &email, string &p, string &status, string &ID);
	Staff();
	~Staff();

	// Mutators
	void setStatus(string s);
	void setID(string id);
	void setPassword(string p);

	// Accessors
	string &getStatus()const;
	string &getID()const;
	string &getPassword()const;
};

#endif // STAFF_H


