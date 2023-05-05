#ifndef STAFF_H
#define STAFF_H
#include "User.h"

class Staff : public User {
protected:
	char ID[100];
	char password[50];
public:
	Staff();
	Staff(string _id, string _password);
	Staff(const Staff& sTmp);
	virtual ~Staff();

	// Mutators
	void setID();
	void setPassword();

	// Accessors
	string getID()const;
	string getPassword()const;

	virtual void printData()const;
};

#endif // STAFF_H


