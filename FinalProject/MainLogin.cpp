/*
    This is the main login for the library.  From this screen a user will be able to choose whether they would like
    to login as a member or a guest, register as a new member, retrieve forgotten username or password or exit the system.
*/
#ifndef MAINLOGIN_CPP
#define MAINLOGIN_CPP

#include "MainLogin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <random>
#include <regex>
#include <iomanip>

using namespace std;

Login::Login() : username(""), password(""){} //default constructor initialized to empty strings

Login::Login(string userN, string userP)
    : username(userN), password(userP) {}

Login::Login(Login& l) : username(l.username), password(l.password) {}

Login::~Login() {}


string Login::getUsername()const {
    return username;
}
string Login::getPassword()const {
    return password;
}
void Login::setUsername(string userN) {
    username = userN;
}
void Login::setPassword(string userP) {
    password = userP;
}

/*void Login::TimeFunction() {
    // current date/time based on current system
    time_t now = time(0);

    // Char array for ctime_s to get time to compile properly using C++ 20
    // This char array holds the string of what the current time is
    char str[26];

    // Get the current time and convert to string, storing it in the str char array
    ctime_s(str, sizeof str, &now);

    cout << str << endl;
}*/

//printMenu() prints the menu options for the login screen
void Login::printMenu()const {
    int choice;
    date.printDate();
    cout << setfill('-') << setw(115) << "" << endl;
    cout << setfill('-') << setw(56) << " LIBRARY LOGIN " << setfill('-') << setw(59) << "" << endl;
    cout << setfill('-') << setw(115) << "" << endl;
    cout << setfill(' ') << setw(53) <<"WELCOME!\n"<< endl;
    cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
    cout << setfill(' ') << setw(66) << "1. Login to Your Account" << endl;
    cout << setfill(' ') << setw(56) << "2. Guest Login" << endl;
    cout << setfill(' ') << setw(65) << "3. Register for Account" << endl;
    cout << setfill(' ') << setw(50) << "4. Exit\n" << endl;
    cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

    cin >> choice;

    switch (choice) {

    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        guestLogin.printMenu();
        //guest();
        break;
    case 3:
        system("cls");
        registration();
        break;
    case 4:
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        cout << "Invalid Choice...Please Try Again...\n" << endl;
        printMenu();
        break;
    }


}

//patron menu of options FIX ME: need to 
void Login::patronMenu()const {
    int choice;
    
    cout << setfill('-') << setw(115) << "" << endl;
    cout << setfill('-') << setw(65) << " WELCOME TO YOUR ACCOUNT" << setfill('-') << setw(50) << "" << endl;
    cout << setfill('-') << setw(116) << "\n" << endl;
    cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
    cout << setfill(' ') << setw(60) << "1. Search Library" << endl;
    cout << setfill(' ') << setw(73) << "2. Update Personal Information" << endl;
    cout << setfill(' ') << setw(59) << "3. View My Media" << endl;
    cout << setfill(' ') << setw(51) << "4. Exit\n" << endl;
    cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

    cin >> choice;

    switch (choice) {

    case 1:
        system("cls");
        invScreen.printMenu();
        break;
    case 2:
        updateInfo();
        break;
    case 3:
        myMedia();
        break;
    case 4:        
        system("cls");
        exit(0);
        break;
    default:
        cout << "Invalid Choice...Please Try Again...\n" << endl;
    }

}

//admin menu of options FIXME: need to link to accounts and be able to update user information
void Login::adminMenu()const {
    int choice;
    while (true) {
        cout << setfill('-') << setw(115) << "" << endl;
        cout << setfill('-') << setw(65) << " WELCOME ADMINISTRATOR " << setfill('-') << setw(50) << "" << endl;
        cout << setfill('-') << setw(116) << "\n" << endl;
        cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(56) << "1. Inventory" << endl;
        cout << setfill(' ') << setw(60) << "2. View Accounts" << endl;
        cout << setfill(' ') << setw(52) << "3. Exit\n" << endl;
        cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

        cin >> choice;

        switch (choice) {

        case 1:
            system("cls");
            invScreen.printMenu();
            break;
        case 2:
            system("cls");
            cout << "Need to open Account information." << endl;//view account should view list of users and allow admin to update infor via  update()
            break;
        case 3:
            system("cls");
            exit(0);
            return;
        default:
            cout << "Invalid Choice...Please Try Again...\n" << endl;
            cin >> choice;
        }
    }
}

//login() allows user to login to borrow books if they have a username and password
void Login::login()const {
    string username;
    string password;
    string line;

    cout << "Please log in or " << endl;
    cout << "Press 1 to return to Main Menu." << endl;
    cout << endl;

    do {
        
        cout << "\nEnter your username: \t" << endl;
        cin >> username;
        if (!username._Equal("1")) {
            cout << "\nEnter your password: \t" << endl;
            cin >> password;
        }
        else {
            system("cls");
            printMenu();
        }
       
    } while (isLoginValid(username, password) != true);

    if (true) {
        system("cls");
        cout << username << " Login Successful!" << endl;
        cout << endl;

        ofstream user;
        user.open("currentUser.txt");

        if (!user.is_open()) {
            cout << "File open was not successful";
        }
        user << username << endl;
        user.close();        

        if (username.at(0) == 'M'){
            adminMenu();
			CurrentSessionInfo::SetAdmin(true);
		}
		else if (username.at(0) == 'E' || line.at(0) == 'S') {
			patronMenu();
		}
		
        system("PAUSE");
        system("cls");
        return;
    }
   
}
  
//guest() allows user to be a guest and use material from the library for 2 hours
void Login::guest()const {
    string gName;
    string media;
    vector<string>guestBorrowList;
    int choice;
    cout << "Press 1 to return to Main Menu." << endl;
    //cout << "Enter your name: \n" << endl;
    cout << endl;
    cout << "Enter your full name: \n" << endl;
    cin.ignore();
    getline(cin, gName);
    
   // cin >> gName;
    cout << endl;
    if (!gName._Equal("1")) {//collect list of items being borrowed
        cout << "What will you be borrowing today?\n (press d when finished)\n" << endl;
        //FIX ME guest should be able to search inventory and borrow.  It should reflect in the library records
        do {
            //cin.ignore();
            getline(cin, media);
            guestBorrowList.push_back(media);
        } while (!media._Equal("d"));
    
        system("cls");
        cout << "Thank you " << gName << "! You are borrowing \n" << endl;
        
        for (int i = 0; i < guestBorrowList.size() - 1; i++) {
            cout << guestBorrowList.at(i) << endl;
        }
        cout << "\nToday is ";
       date.printDate();
        cout << "Please return items in 2 hours." << endl;
        cout << endl;
        do {
            cout << "Press 1 to return to Main Menu" << endl;
            cout << "Press 2 to exit" << endl;
            cin >> choice;
        } while (choice != 1 && choice != 2);
        if (choice == 1) {
            printMenu();
        }
        else {
            system("cls");
            cout << "You have exited.Thank you!" << endl;
            system("PAUSE");
            system("cls");
            printMenu();
        }
    }
    else {
        system("cls");
        printMenu();
    }

}

//registration() allows user to register for an account if they don't have one already
void Login::registration()const {
    string fName, lName, address, phoneNum, email, id, libID, password;
    char pos;
    int choice;

    cout << "Press 1 to return to Main Menu or" << endl;
    
    do {
        cout << "\nEnter your first name: \t" << endl;
        cin.ignore();
        getline(cin, fName);
        if (fName._Equal("1")) {
            system("cls");
            printMenu();
        }        
    } while (isValidName(fName) != true);

    do {
        cout << "\nEnter your last name: \t" << endl;
        getline(cin, lName);
    } while (isValidName(lName) != true);

    address = isValidAddress();
   
    do {//make sure phone number is valid
        cout << "\nEnter your phone number: \t" << endl;
        getline(cin, phoneNum);
    } while (formatPhone(phoneNum) != true);
    if (true) {
        phoneNum.insert(0, "(");
        phoneNum.insert(4, ")");
        phoneNum.insert(8, "-");
    }

    do {//make sure email is valid
        cout << "\nEnter your email: \t" << endl;
        getline(cin, email);
    }while(isEmailValid(email) != true);    
    cout << endl;

    do {
        cout << "Enter your position(M/E/S)" << endl;
        cout << "Staff member M\nEmployee E\nStudent S \t" << endl;
        cin >> pos;
    } while (pos != 'M' && pos != 'E' && pos != 'S' && pos != 'm' && pos != 'e' && pos != 's');

    //check positon and issue username and password
    switch (pos) {
    case 'M':
    case 'm':
        cout << "\nEnter your staff ID: \t" << endl;
        libID = "M" + randomLibID();
        password = randomPass();
        break;
    case 'E':
    case 'e':
        cout << "\nEnter your employee ID: \t" << endl;
        libID = "E" + randomLibID();
        password = randomPass();
        break;
    case 'S':
    case 's':
        cout << "\nEnter your student ID: \t" << endl;
        libID = "S" + randomLibID();
        password = randomPass();
        break;
    default:
        cout << "\nNot a valid entry." << endl;
        cout << "Enter your position(M/E/S)" << endl;
        cout << "Staff member M\nEmployee E\nStudent S \t" << endl;
        cin >> pos;
    }
    cin.ignore();
    getline(cin, id);
    cout << endl;
    char correct;
    //check that information entered is correct, if it is save to file if it is not, enter new information  
    //FIXME write switch to allow user to pick which part is incorrect and only update that?
    cout << "Is the information correct? Y/N" << endl;
    cout << "Name: " << fName << " " << lName << "\nAddress: " << address << "\nPhone: " << phoneNum << "\nEmail: " << email
        << "\nPosition: " << pos << "\nID: " << id << endl;
    cin >> correct;
    switch (correct) {
    case 'Y':
    case'y':    
    {
        //open file to store registration information
        ofstream file;
        file.open("records.txt", ios::in | ios::app);
        if (!file.is_open()) {
            cout << "File open unsuccessful" << endl;
        }

        //store memeber registration information in records.txt
        if (file.is_open()) {
            //file << "Name: " << fName << " " << lName << "\tAddress: " << address << "\tPhone: " << phoneNum << "\tEmail: " << email
              //  << "\tPosition: " << pos << "\tID: " << id << "\tLibrary Login: " << libID << "\tPassword: " << password << "\t" << endl;
            file << "Name: " << fName << " " << lName << "\nAddress: " << address << "\nPhone: " << phoneNum << "\nEmail: " << email
                << "\nPosition: " << pos << "\nID: " << id << "\nLibraryID: " << libID << "\nPassword: " << password << endl;
            file << endl;

        }
        file.close();
        //open file to store username and password
        ofstream userpassList;
        userpassList.open("userpass.txt", ios::in | ios::app);
        if (!userpassList.is_open()) {
            cout << "File open unsuccessful" << endl;
        }
        //store username and password in userpassList.txt
        if (userpassList.is_open()) {
            userpassList << libID << "\t" << password << endl;
        }
        userpassList.close();

        system("cls");
        cout << "\nRegistration is successful!" << endl;
        cout << "\nYour Library ID is: \t" << libID << endl;
        cout << "\nYour Password is: \t" << password << endl;
        cout << endl;
        cout << "\nPress 1 to return to Main Menu" << endl;
        cout << "\nPress 2 to exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            printMenu();
            break;
        case 2:
            system("cls");
            cout << "Thank you!  Have a great day." << endl;
            system("PAUSE");
            printMenu();
            break;
        default:
            system("cls");
            cout << "Invalid Choice...Please Try Again...\n" << endl;
            break;
        }
    }
        break;
    case 'N':
    case 'n':
        system("cls");
        registration();
        break;
    default:
        cout << "Not a valid entry." << endl;
    }

}

//assigns a random libID to new members
string Login::randomLibID() {
    srand(time(0));
    int IDLength = 4;
    static const char IDNum[] =
        "0123456789";
    string libID;
    libID.reserve(IDLength);

    for (int i = 0; i < IDLength; i++) {
        libID += IDNum[rand() % (sizeof(IDNum) - 1)];
    }

    return libID;
}
   
//assigns a random password to new members
string Login::randomPass() {
    srand(time(0));
    int passLength = 5;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string pass;
    pass.reserve(passLength);

    for (int i = 0; i < passLength; i++) {
        pass += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return pass;
}

//validate username and password match to login
bool Login::isLoginValid(string &inUser, string &inPass) {
    string username, password;

    ifstream read("userpass.txt");

    if (!read.is_open()) {
        cout << "File not opened successfully";
    }

    while (read >> username >> password) {//check to see if password exists
        if (inUser == username && inPass == password) {
            return true;
        }
    }
    system("cls");
    cout << "\nUsername or Password not found.  Please try again." << endl;
    system("PAUSE");
    system("cls");

    return false;
    read.close();
}

//validate email format
bool Login::isEmailValid(string &email) {
    //create regex variable pattern with requirements for valid email
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    //match the email passed in to the regex pattern and return true if it matches

    bool valid = regex_match(email, pattern);
    if (!valid) {
        cout << "\nEnter a valid email.";
    }
    return valid;

}

//format phone number
bool Login::formatPhone(string &phone) {
    const int NUM_LENGTH = 10;

    if (phone.length() != NUM_LENGTH) {
        cout << "Phone number must contain only 10 digits starting with the area code" << endl;
        for (char ch : phone) {
            if (!isdigit(ch)) {
                return false;
            }
        }
    }
    else {
        return true;
    }
}       
      

//limit first and last name to less than 20 letters and only allow letters
bool Login::isValidName(string &name) {//FIXME not working yet. 
    const int NUM_LENGTH = 20;

    if (name.length() >= NUM_LENGTH || name.length() == 0) {
        cout << "Invalid input. Please try again." << endl;
       for (int i = 0; i < name.length(); i++) {
            if (!isalpha(name.at(i))) {
                break;
            }
         }  
       return false;
   } 
    else {
        return true;
    }

}
 
//asks for address information
string Login::isValidAddress()const {
    string street;
    string city;
    string state;
    string zipCode;
    do {
        cout << "\nEnter your address: \nStreet:\t" << endl;
        getline(cin, street);
            if (street.length() > 50) {
                cout << "Invalid Street.  Please try again." << endl;
            }
    } while (street.length() > 50);
    
    do {
        cout << "\nCity:\t" << endl;
        getline(cin, city);
             if (city.length() > 25) {
                cout << "Invalid City.  Please try again." << endl;
             }
    } while (city.length() > 25);
    
    do {
        cout << "\nState:\t" << endl;
        getline(cin, state);
            if (state.length() > 30) {
                cout << "Invalid State.  Please try again." << endl;
            }
    } while (state.length() > 30);

    do {
        cout << "\nZip Code:\t" << endl;
        getline(cin, zipCode);
        if (zipCode.length() != 5) {
            cout << "Invalid Zip Code.  Please try again." << endl;
        }
        else {
            for (char ch : zipCode) {
                if (!isdigit(ch)) {
                    getline(cin, zipCode);
                }
            }
        }
    } while (zipCode.length() != 5);

    string address = street + " " + city + ", " + state + " " + zipCode;

    return address;

}

void Login::updateInfo()const {
    system("cls");
    int choice;
    string name, address, email, phone;
    cout << "Get user info" << endl;//FIX ME
    cout << "What would you like to update?" << endl;
    cout << setfill(' ') << setw(68) << "1. Name" << endl;
    cout << setfill(' ') << setw(68) << "2. Address" << endl;
    cout << setfill(' ') << setw(68) << "3. Email" << endl;
    cout << setfill(' ') << setw(68) << "4. Phone" << endl;
    cout << setfill(' ') << setw(68) << "5. Return" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cin >> name;
        break;
    case 2:
        cin >> address;
        break;
    case 3:
        cin >> email;
        break;
    case 4:
        cin >> phone;
        break;
    case 5:
        system("cls");
        exit(0);
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        cin >> choice;
    }

}

void Login::myMedia()const{
    system("cls");
    cout << "Show list of books checked out to this user." << endl;
}
//void Login::borrow(){}
//void Login::placeHold(){}
//void Login::renew(){}
//void Login::checkout(){}
//void Login::returnBook(){}



#endif // !MAINLOGIN_CPP