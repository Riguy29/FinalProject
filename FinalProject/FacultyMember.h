#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H
#include "User.h"

class FacultyMember : public User {
protected:
	char ID[100];
	char password[50];
public:
	FacultyMember();
	FacultyMember(userTypes _userType, int libID, string _firstName, string _lastName, 
		string _address, string _phoneNum, string _email, string _id, string _password);
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


