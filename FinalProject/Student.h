#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User {
protected:
	const char* status;
	const char* ID;
	const char* password;
public:
	Student(const char* fName, const char* lName, const char* address, 
		const char* phone, const char* email, const char* p, const char* status, const char* ID);
	Student();
	Student(const Student& sTmp);
	~Student();

	// Mutators
	void setStatus(const char* s);
	void setID(const char* id);
	void setPassword(const char* p);

	// Accessors
	const char* getStatus()const;
	const char* getID()const;
	const char* getPassword()const;
};

#endif // STUDENT_H