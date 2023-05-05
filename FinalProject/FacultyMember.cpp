#include "FacultyMember.h"

// Default Constructor
FacultyMember::FacultyMember():User() {
    userType = facultyMember;
    strncpy_s(ID, "Not Set", 100);
}

// Overloaded Default Constructor
FacultyMember::FacultyMember(userTypes _userType, int libID, string _firstName, string _lastName,
    string _address, string _phoneNum, string _email, string _id, string _password):User(
    facultyMember, libID, _firstName, _lastName, _address, _phoneNum, _email, _password) {
    strncpy_s(ID, _id.c_str(), 100);
}

// Copy Constructor
FacultyMember::FacultyMember(const FacultyMember& cFMem):User(cFMem) {
    strncpy_s(ID, cFMem.ID, 100);
}

// Destructor
FacultyMember::~FacultyMember() {}

// Mutators 
void FacultyMember::setID() {
    string fID;
    bool valid = false;

    system("cls");

    do {
        cout << "Enter Faculty ID: " << endl;
        getline(cin, fID);

        // Limit input to 50 chars
        if (fID.length() > 50 || fID.length() == 0) {
            system("cls");
            cout << "Faculty ID must be greater than 0 and less than 50 characters long!" << endl;
        }
        else {
            strcpy_s(ID, sizeof(ID), fID.c_str());
            valid = true;
        }

    } while (!valid);
}

// Accessors
string FacultyMember::getID()const { return ID; }
void FacultyMember::printData()const {
	User::printData();
	cout << "Faculty ID: " << getID() << endl;
}