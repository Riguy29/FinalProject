#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H
#include "User.h"

class FacultyMember : User {
protected:
	const char* status;
	const char* ID;
	const char* password;
public:
	FacultyMember(const char* fName, const char* lName, const char* address, const char* phone, 
		const char* email, const char* p, const char* status, const char* ID);
	FacultyMember();
	~FacultyMember();
	FacultyMember(const FacultyMember& newU);

	// Mutators
	void setStatus(const char* s);
	void setID(const char* id);
	void setPassword(const char* p);

	// Accessors
	const char* getStatus()const;
	const char* getID()const;
	const char* getPassword()const;
};

#endif // FACULTY_MEMBER_H


