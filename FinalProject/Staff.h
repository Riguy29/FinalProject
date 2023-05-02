#ifndef STAFF_H
#define STAFF_H
#include "User.h"

class Staff : User {
protected:
	const char* status;
	const char* ID;
	const char* password;
public:
	Staff(const char* fName, const char* lName, const char* address, const char* phone, 
		const char* email, const char* p, const char* status, const char* ID);
	Staff();
	Staff(const Staff& sTmp);
	virtual ~Staff();

	// Mutators
	void setStatus(const char* s);
	void setID(const char* id);
	void setPassword(const char* p);

	// Accessors
	const char* getStatus()const;
	const char* getID()const;
	const char* getPassword()const;
};

#endif // STAFF_H


