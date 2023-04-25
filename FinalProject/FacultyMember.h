#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H
#include "User.h"

class FacultyMember : User {
protected:
	string status;
	string ID;
	string password;
public:
	FacultyMember(string fName, string lName, string address, string phone, 
		string email, string p, string status, string ID);
	FacultyMember();
	~FacultyMember();

	// Mutators
	void setStatus(string s);
	void setID(string id);
	void setPassword(string p);

	// Accessors
	string getStatus()const;
	string getID()const;
	string getPassword()const;
};

#endif // FACULTY_MEMBER_H


