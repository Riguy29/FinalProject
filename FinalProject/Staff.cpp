#include "Staff.h"

// Default constructor
Staff::Staff():User() {
	userType = staff;
	strncpy_s(ID, "Not Set", 100);
}

// Overloaded Default constructor
Staff::Staff(userTypes _userType, int libID, string _firstName, string _lastName,
    string _address, string _phoneNum, string _email, string _id, string _password) :User(
        staff, libID, _firstName, _lastName, _address, _phoneNum, _email, _password) {
    strncpy_s(ID, _id.c_str(), 100);
}

// Copy Constructor
Staff::Staff(const Staff& sTmp):User(sTmp) {
	strncpy_s(ID, sTmp.ID, 100);
}

// Destructor
Staff::~Staff() {}

// Mutators
void Staff::setID() {
    string sID;
    bool valid = false;

    system("cls");

    do {
        cout << "Enter Staff ID: " << endl;
        getline(cin, sID);

        // Limit user address to 50 chars
        if (sID.length() > 50 || sID.length() == 0) {
            system("cls");
            cout << "Staff ID must be greater than 0 and less than 50 characters long!" << endl;
        }
        else {
            strcpy_s(ID, sizeof(ID), sID.c_str());
            valid = true;
        }

    } while (!valid);
}

// Accessors
string Staff::getID()const { return ID; }
void Staff::printData()const {
	User::printData();
	cout << "Faculty ID: " << getID() << endl;
}