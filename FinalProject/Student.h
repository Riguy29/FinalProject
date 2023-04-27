#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User {
protected:
	string *status;
	string *ID;
	string *password;
public:
	Student(string &fName, string &lName, string &address, 
		string &phone, string &email, string &p, string &status, string &ID);
	Student();
	~Student();

	// Mutators
	void setStatus(string s);
	void setID(string id);
	void setPassword(string p);

	// Accessors
	string &getStatus()const;
	string &getID()const;
	string &getPassword()const;
};

#endif // STUDENT_H