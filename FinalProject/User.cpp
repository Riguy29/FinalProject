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

    strncpy_s(firstName, "Not Set", sizeof(firstName));
    strncpy_s(lastName, "Not Set", sizeof(lastName));
    strncpy_s(address, "Not Set", sizeof(address));
    strncpy_s(phoneNum, "Not Set", sizeof(phoneNum));
    strncpy_s(email, "Not Set", sizeof(email));
}

// Overloaded Default Constructor
User::User(userTypes _userType, int _libID, string _firstName, string _lastName, string _address, string _phoneNum, string _email) {
    userType = _userType;
    libID = _libID;

    strncpy_s(firstName, _firstName.c_str(), sizeof(firstName));
    strncpy_s(lastName, _lastName.c_str(), sizeof(lastName));
    strncpy_s(address, _address.c_str(), sizeof(address));
    strncpy_s(phoneNum, _phoneNum.c_str(), sizeof(phoneNum));
    strncpy_s(email, _email.c_str(), sizeof(email));
}

// Copy Constructor
User::User(const User& cUsr) {
	userType = cUsr.userType;
    libID = cUsr.libID;

    strncpy_s(firstName, cUsr.firstName, sizeof(firstName));
    strncpy_s(lastName, cUsr.lastName, sizeof(lastName));
    strncpy_s(address, cUsr.address, sizeof(address));
    strncpy_s(phoneNum, cUsr.phoneNum, sizeof(phoneNum));
    strncpy_s(email, cUsr.email, sizeof(email));
}

// Destructor
User::~User() {}

// Accessors
string User::getFirstName()const { return firstName; }
string User::getLastName()const { return lastName; }
string User::getAddress()const { return address; }
string User::getPhoneNumber()const { return phoneNum; }
string User::getEmail()const { return email; }
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

void User::setLibID(int i) { libID = i; }
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

/*
//functions for updating user information
void User::updateFirstName() {
if(isAdmin == true){
    string userUsername;
    cout << "Enter username for account you want to access"<< endl;
    cin >> userUsername;

    for(int i = 0; i < CurrentSessionInfo::userList.size(); i++){
        if(CurrentSessionInfo::userList.at(i)->GetUsername().find(userUsername)!=string::npos){
            cout << userList.at(i)->getFirstName() << " " << userList.at(i)->getLastName();

            cout << "Enter New First Name: " << endl;
            const char* newFName;    
            do {
               cin >> newFName;
               Login::isValidName(newFName);
            } while (!true);
               setFirstName(newFName);
               cout << "New Name: " << userList.at(i)->getFirstName() << " " << userList.at(i)->getLastName();
         }
     }
 }
 else {
   cout << "Enter New First Name: " << endl;
            const char* newFName;    
            do {
                cin >> newFName;
               Login::isValidName(newFName);
            } while (!true);
                 setFirstName(newFName);
                 cout << "New Name: " << getFirstName() << " " << getLastName();

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
*/