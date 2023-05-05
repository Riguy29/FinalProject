#include "Student.h"

// Default constructor
Student::Student():User() {
	userType = student;
	strncpy_s(ID, "Not Set", 100);
}

// Overloaded Default Constructor
Student::Student(userTypes _userType, int libID, string _firstName, string _lastName,
    string _address, string _phoneNum, string _email, string _id, string _password):User(
        student, libID, _firstName, _lastName, _address, _phoneNum, _email, _password) {
    strncpy_s(ID, _id.c_str(), 100);
}

// Copy Constructor
Student::Student(const Student& sTmp):User(sTmp) {
	strncpy_s(ID, sTmp.ID, 100);
}

// Destructor
Student::~Student() {}

// Mutators
void Student::setID() {
    string sID;
    bool valid = false;

    system("cls");

    do {
        cout << "Enter Student ID: " << endl;
        getline(cin, sID);

        // Limit user address to 50 chars
        if (sID.length() > 50 || sID.length() == 0) {
            system("cls");
            cout << "Student ID must be greater than 0 and less than 50 characters long!" << endl;
        }
        else {
            strcpy_s(ID, sizeof(ID), sID.c_str());
            valid = true;
        }

    } while (!valid);
}

// Accessors
string Student::getID()const { return ID; }

void Student::printData()const {
	User::printData();
	cout << "Student ID: " << getID() << endl;
}