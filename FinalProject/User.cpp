/*
	User.cpp
	This cpp file implements the User object functions, including:
	Accessors, mutators, constructors, and destructors

	This cpp file also performs all error checking within the mutator functions for object creation
*/

#include "User.h"

// Default Constructor
User::User() {
    userType = student;
    libID = 0;

    strncpy_s(firstName, "Not Set", 50);
    strncpy_s(lastName, "Not Set", 50);
    strncpy_s(address, "Not Set", 200);
    strncpy_s(phoneNum, "Not Set", 50);
    strncpy_s(email, "Not Set", 200);
    strncpy_s(password, "Not Set", 50);
}

// Overloaded Default Constructor
User::User(userTypes _userType, int _libID, string _firstName, string _lastName, string _address, string _phoneNum, string _email, string _password) {
    userType = _userType;
    libID = _libID;

    strncpy_s(firstName, _firstName.c_str(), 50);
    strncpy_s(lastName, _lastName.c_str(), 50);
    strncpy_s(address, _address.c_str(), 200);
    strncpy_s(phoneNum, _phoneNum.c_str(), 50);
    strncpy_s(email, _email.c_str(), 50);
    strncpy_s(password, _password.c_str(), 50);
}

// Copy Constructor
User::User(const User& cUsr) {
	userType = cUsr.userType;
    libID = cUsr.libID;

    strncpy_s(firstName, cUsr.firstName, 50);
    strncpy_s(lastName, cUsr.lastName, 50);
    strncpy_s(address, cUsr.address, 200);
    strncpy_s(phoneNum, cUsr.phoneNum, 50);
    strncpy_s(email, cUsr.email, 200);
    strncpy_s(password, cUsr.password, 50);
}

// Destructor
User::~User() {}

// Accessors
string User::getFirstName()const { return firstName; }
string User::getLastName()const { return lastName; }
string User::getAddress()const { return address; }
string User::getPhoneNumber()const { return phoneNum; }
string User::getEmail()const { return email; }
string User::getPassword()const { return password; }

User::userTypes User::getUserType() { return userType; }
int User::getLibID()const { return libID; }

// Mutators
void User::setFirstName() {
    string fName;
    bool valid = false;

    system("cls");

    cin.clear();
    cin.ignore();
    
    do {
        cout << "Enter First Name: " << endl;
        getline(cin, fName);

        // First name greater than 20 or 0
        if (fName.length() > 20 || fName.length() == 0) {
            system("cls");
            cout << "Name must have a length less than 20 and greater than 0 characters!" << endl;
        } else if (!containsOnlyLetters(fName)) { // Must only contain characters
            system("cls");
            cout << "Name must only contain letters!" << endl;
        } else {
            strcpy_s(firstName, sizeof(firstName), fName.c_str());
            valid = true;
        }
    } while (!valid);
}

void User::setLastName() { 
    string lName;
    bool valid = false;

    system("cls");

    do {
        cout << "Enter Last Name: " << endl;
        getline(cin, lName);

        // First name greater than 20 or 0
        if (lName.length() > 20 || lName.length() == 0) {
            system("cls");
            cout << "Name must have a length less than 20 and greater than 0 characters!" << endl;
        }
        else if (!containsOnlyLetters(lName)) { // Must only contain characters
            system("cls");
            cout << "Name must only contain letters!" << endl;
        }
        else {
            strcpy_s(lastName, sizeof(lastName), lName.c_str());
            valid = true;
        }
    } while (!valid);
}

void User::setAddress() { 
    string ad;
    bool valid = false;
    
    system("cls");

    do {
        cout << "Enter Address: " << endl;
        getline(cin, ad);

        // Limit user address to 200 chars
        if (ad.length() < 200 || ad.length() > 0) {
            strcpy_s(address, sizeof(address), ad.c_str());
            valid = true;
        }
        else {
            system("cls");
            cout << "Address must be greater than 0 and less than 200 characters long!" << endl;
        }

    } while (!valid);
}

void User::setPhoneNumber() {
    string tmpStr;
    bool valid = false;
    
    system("cls");

    // Will be used later in function to compare number format :)
    regex r("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}");

    do {
        cout << "Enter Phone Number in format (920-123-4567): " << endl;
        getline(cin, tmpStr);

        // Try if user entered correct format
        if (regex_match(tmpStr, r)) {
            strcpy_s(phoneNum, sizeof(phoneNum), tmpStr.c_str());
            valid = true;
        }
        else {
            system("cls");
            cout << "Phone Number must be in format (920-123-4567)!" << endl;
        }
       
    } while (!valid);
}

void User::setEmail() { 
    string em;
    bool valid = false;

    system("cls");

    regex r("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    do {
        cout << "Enter Email Address: " << endl;
        getline(cin, em);

        // Limit user address to 200 chars
        if (em.length() > 200 || em.length() == 0) {
            system("cls");
            cout << "Email Address must be greater than 0 and less than 200 characters long!" << endl;
        }
        else if (regex_match(em, r)) {
            strcpy_s(email, sizeof(email), em.c_str());
            valid = true;
        }
        else {
            system("cls");
            cout << "Email Address must be formatted as Example@example.example" << endl;
            
        }

    } while (!valid);
}

void User::setPassword() {
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

void User::setLibID(int i) { libID = i; }
void User::setUserType(userTypes type) { userType = type; }

void User::printMenu() {
    int accountChoice;
    //if(!Admin){
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
            setFirstName();
            break;
        case 2:
            setLastName();
            break;
        case 3:
            setAddress();
            break;
        case 4:
            setPhoneNumber();
            break;
        case 5:
            setEmail();
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

// Checks if the passed in string contains only letters
bool User::containsOnlyLetters(string const& str) {
    return std::regex_match(str, std::regex("^[A-Za-z]+$"));
}

// Prints all the data
void User::printData()const {
    cout << endl;
    cout << "Name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Library ID: " << getLibID() << endl;
}
