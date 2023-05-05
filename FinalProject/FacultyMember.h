#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H
#include "User.h"

class FacultyMember : public User {
protected:
	char ID[100];
	char password[50];
public:
	FacultyMember();
	FacultyMember(string _id, string _password);
	FacultyMember(const FacultyMember& newU);
	virtual ~FacultyMember();

	// Mutators
	void setID();
	void setPassword();

	// Accessors
	string getID()const;
	string getPassword()const;

	virtual void printData()const;
};

#endif // FACULTY_MEMBER_H


