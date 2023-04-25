#ifndef GUEST_H
#define GUEST_H
#include "User.h"

class Guest : public User {
protected:
	string status;
public:
	Guest();
	Guest(string fName, string lName, string address, 
		string phone, string email, string status);
	~Guest();

	// Mutators
	void setStatus(string s);

	// Accessors
	string getStatus()const;
};

#endif // GUEST_H
