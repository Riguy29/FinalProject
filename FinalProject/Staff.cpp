#include "Staff.h"

// Default constructor
Staff::Staff():User() {
	userType = staff;
	strcpy_s(ID, sizeof(ID), "");
	strcpy_s(password, sizeof(password), "");
}

// Copy Constructor
Staff::Staff(const Staff& sTmp) : User(sTmp) {
	strcpy_s(ID, sizeof(ID), sTmp.ID);
	strcpy_s(password, sizeof(password), sTmp.password);
}

// Destructor
Staff::~Staff() {}

// Mutators TODO: Add stuffs
void Staff::setID() {

}

void Staff::setPassword() {
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
string Staff::getID()const { return ID; }
string Staff::getPassword()const { return password; }

void Staff::printData()const {
	User::printData();
	cout << "Faculty ID: " << getID() << endl;
}