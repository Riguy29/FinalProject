#include "Staff.h"

// Default constructor
Staff::Staff():User() {
	userType = staff;
	strncpy_s(ID, "Not Set", sizeof(ID));
	strncpy_s(password, "Not Set", sizeof(password));
}

// Overloaded Default constructor
Staff::Staff(string _id, string _password):User() {
    userType = staff;
    strncpy_s(ID, _id.c_str(), sizeof(ID));
    strncpy_s(password, _password.c_str(), sizeof(password));
}

// Copy Constructor
Staff::Staff(const Staff& sTmp):User(sTmp) {
	strncpy_s(ID, sTmp.ID, sizeof(ID));
	strncpy_s(password, sTmp.password, sizeof(password));
}

// Destructor
Staff::~Staff() {}

// Mutators TODO: Add stuffs
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

void Staff::setPassword() {
    string p;
    bool valid = false;
    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    system("cls");

    do {
        cout << "Enter Password: " << endl;
        getline(cin, p);


        // Check for at least one uppercase and lowercase letter, and one number
        for (int i = 0; i < p.size(); i++) {
            if (isupper(p[i])) {
                upper = true;
            }

            if (isdigit(p[i])) {
                digit = true;
            }

            if (islower(p[i])) {
                lower = true;
            }
        }

        // Check for special characters
        if (p.find('$') != string::npos) {
            special = true;
        }
        else if (p.find('#') != string::npos) {
            special = true;
        }
        else if (p.find('%') != string::npos) {
            special = true;
        }
        else if (p.find('!') != string::npos) {
            special = true;
        }

        // Limit input to 50 chars
        if (p.length() > 50 || p.length() == 0) {
            system("cls");
            cout << "Password must be greater than 0 and less than 50 characters long!" << endl;
        }
        else if (!upper) {
            system("cls");
            cout << "Password must contain at least one uppercase letter!" << endl;
        }
        else if (!lower) {
            system("cls");
            cout << "Password must contain at least one lowercase letter!" << endl;
        }
        else if (!digit) {
            system("cls");
            cout << "Password must contain at least one number!" << endl;
        }
        else if (!special) {
            system("cls");
            cout << "Password must contain at least one special character ($#%!)" << endl;
        }
        else {
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