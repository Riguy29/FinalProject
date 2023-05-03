#include "FacultyMember.h"

// Default Constructor
FacultyMember::FacultyMember():User() {
	userType = facultyMember;
	strcpy_s(ID, sizeof(ID), "");
	strcpy_s(password, sizeof(password), "");
}

// Copy Constructor
FacultyMember::FacultyMember(const FacultyMember& cFMem) : User(cFMem) {
	strcpy_s(ID, sizeof(ID), cFMem.ID);
	strcpy_s(password, sizeof(password), cFMem.password);
}

// Destructor
FacultyMember::~FacultyMember() {}

// Mutators TODO: Implement Exception handling for adding and mod of FacultyMembers
void FacultyMember::setID() {

}

void FacultyMember::setPassword() {
    string p;
    bool valid = false;

    do {
        cout << "Enter Password: " << endl;
        getline(cin, p);

        // Limit user address to 50 chars
        if (p.length() > 50 || p.length() == 0) {
            system("cls");
            cout << "Password must be greater than 0 and less than 50 characters long!" << endl;
        }
        else { // Use regex here, just takes string thats less than 200 and greater than 0 atm for testing purposes
            strcpy_s(password, sizeof(password), p.c_str());
            valid = true;
        }

    } while (!valid);
}

// Accessors
string FacultyMember::getID()const { return ID; }
string FacultyMember::getPassword()const { return password; }

void FacultyMember::printData()const {
	User::printData();
	cout << "Faculty ID: " << getID() << endl;
}