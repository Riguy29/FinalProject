/*
	User.cpp
	This cpp file implements the User object functions, including:
	Accessors, mutators, constructors, and destructors

	This cpp file also performs all error checking within the mutator functions for object creation
*/

#include "User.h"

// Default Constructor
User::User():userType(student), firstName(""), lastName(""),
address(""), phoneNum(""), email("") {}

// Overloaded Constructor
User::User(userTypes typeOfUser, const char* fName, const char* lName, const char* a, const char* p, const char* e) {
	userType = typeOfUser;
	firstName = fName;
	lastName = lName;
	address = a;
	phoneNum = p;
	email = e;
}

// Copy Constructor
User::User(const User& cUsr) {
	userType = cUsr.userType;
	firstName = cUsr.firstName;
	lastName = cUsr.lastName;
	address = cUsr.address;
	phoneNum = cUsr.phoneNum;
	email = cUsr.email;
}

// Destructor
User::~User() { cout << "User object destroyed: Please remove this before deployment!" << endl; }

// Accessors
const char* User::getFirstName()const { return firstName; }
const char* User::getLastName()const { return lastName; }
const char* User::getAddress()const { return address; }
const char* User::getPhoneNumber()const { return phoneNum; }
const char* User::getEmail()const { return email; }
User::userTypes User::getUserType() { return userType; }

// Mutators TODO: Implement error checking for user creation and mod
void User::setFirstName() {
    cout << "Enter First Name: " << endl;
    string fName;
    const int NAME_MAX_LENGTH = 20;
    getline(cin, fName);

    
}

void User::setLastName() { 

}

void User::setAddress() { 

}

void User::setPhoneNumber() {

}

void User::setEmail() { 

}

void User::setUserType(userTypes type) { userType = type; }

void User::printMenu() {
    
    int accountChoice;
    cout << setfill('-') << setw(116) << "\n" << endl;
    cout << setfill(' ') << setw(68) << getFirstName() << endl;
    cout << setfill('-') << setw(116) << "\n" << endl;
    cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
    cout << setfill(' ') << setw(60) << "1. Update Personal Information" << endl;
    cout << setfill(' ') << setw(58) << "2. View My Books" << endl;
    cout << setfill(' ') << setw(51) << "0. Return\n" << endl;
    cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

    cin >> accountChoice;

    switch (accountChoice) {
    case 0:
        return;
    case 1:
        int updateChoice;
        cout << setfill(' ') << setw(60) << "What would you like to update?" << endl;
        cout << setfill(' ') << setw(60) << "1. First Name" << endl;
        cout << setfill(' ') << setw(60) << "2. Last Name" << endl;
        cout << setfill(' ') << setw(60) << "3. Address" << endl;
        cout << setfill(' ') << setw(60) << "4. Phone Number" << endl;
        cout << setfill(' ') << setw(60) << "5. Email" << endl;
        cout << setfill(' ') << setw(60) << "0. Return\n" << endl;
        cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";
        cin >> updateChoice;
        switch (updateChoice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            return;
        default:
            cout << "Invalid Choice" << endl;
        }

        break;
    case 2:
        //FIXME: open currentUser bookList
        cout << "Books you currently have checked out are: " << endl;
        for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++) {
            cout << CurrentSessionInfo::mediaList.at(i) << endl;
        }
        cout << endl;

        int returnInput;
        do {
            cout << "Press 0 to return to previous screen" << endl;
            cin >> returnInput;
        } while (returnInput != 0);
        break;
    default:
        cout << "Invalid Choice" << endl;
    }
    
}


//functions for updating user information
void User::updateFirstName() {
    cout << "Enter New First Name: " << endl;
    const char* newFName;
    do {
        cin >> newFName;
        Login::isValidName(newFName);
    } while (!true);
    setFirstName(newFName);        
}
void User::updateLastName() {
    cout << "Enter New Last Name: " << endl;
    const char* newLName;
    do {
        cin >> newLName;
        Login::isValidName(newLName);
    } while (!true);
    setLastName(newLName);   
}
void User::updateAddress() {
    cout << "Enter New Address: " << endl;
    const char* newAddress = isValidAddress();
    setAddress(newAddress);
}
void User::updatePhoneNumber() {
    cout << "Enter New Phone Number: " << endl;
    const char* newPhone;
    do {
        cin >> newPhone;
        formatPhone(newPhone);
    } while (!true);
    setPhoneNumber(newPhone);
}
void User::updateEmail()const {
    cout << "Enter New Email: " << endl;
    const char* newEmail;
    do {
        cin >> newEmail;
        isEmailValid(newEmail);
    } while (!valid);
    setEmail(newEmail);
}
void User::updateUserType() {
    cout << "Enter New User Type: " << endl;
    const char* newUserType;
    do {
        cin >> newUserType;
    } while (newUserType != "facultyMember" || newUserType != "student" || newUserType != "staff");
    setUserType(newUserType);
}