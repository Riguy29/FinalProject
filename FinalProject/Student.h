#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User {
protected:
	char ID[100];
	char password[50];
public:
	Student();
	Student(userTypes _userType, int libID, string _firstName, string _lastName,
		string _address, string _phoneNum, string _email, string _id, string _password);
	Student(const Student& sTmp);
	virtual ~Student();

	// Mutators
	void setID();
	void setPassword();

	// Accessors
	string getID()const;
	string getPassword()const;

	virtual void printData()const;
};

#endif // STUDENT_H