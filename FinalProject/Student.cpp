#include "Student.h"

// Default constructor
Student::Student():User() {
	userType = student;
	strncpy_s(ID, "Not Set", 100);
	strncpy_s(password, "Not Set", 50);
}

// Overloaded Default Constructor
Student::Student(userTypes _userType, int libID, string _firstName, string _lastName,
    string _address, string _phoneNum, string _email, string _id, string _password):User(
        student, libID, _firstName, _lastName, _address, _phoneNum, _email) {
    strncpy_s(ID, _id.c_str(), 100);
    strncpy_s(password, _password.c_str(), 50);
}

// Copy Constructor
Student::Student(const Student& sTmp):User(sTmp) {
	strncpy_s(ID, sTmp.ID, 100);
	strncpy_s(password, sTmp.password, 50);
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

void Student::setPassword() {
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
string Student::getID()const { return ID; }
string Student::getPassword()const { return password; }

void Student::printData()const {
	User::printData();
	cout << "Student ID: " << getID() << endl;
}