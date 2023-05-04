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

#include "CurrentSessionInfo.h"

using namespace std;

// Default constructor
Login::Login() {} 
Login::Login(Login& l) {}
Login::~Login() {}

// printMenu() prints the menu options for the login screen
void Login::printMenu() {
    int choice;
    bool isValidChoice = true;
    do
    {
        date.printDate();
        cout << setfill('-') << setw(115) << "" << endl;
        cout << setfill('-') << setw(56) << " LIBRARY LOGIN " << setfill('-') << setw(59) << "" << endl;
        cout << setfill('-') << setw(115) << "" << endl;
        cout << setfill(' ') << setw(53) << "WELCOME!\n" << endl;
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
            InventoryScreen::SearchForMedia();
            //guestLogin.printMenu();
            //guest();
            break;
        case 3:
            system("cls");
            registration();
            break;
        case 4:
            system("cls");
            CurrentSessionInfo::SaveAllData(); //Before we exit save all our data
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid Choice...Please Try Again...\n" << endl;
            break;
        }
    } while (true);
    }

void Login::userHomeMenu()const {   
    int choice;
    bool validChoice = true;
    ifstream currUser;
    string username;
    currUser.open("currentUser.txt");

    if (!currUser.is_open()) {
        cout << "File open was not successful :(";
    }

    while (true)//Using a while true loop so that when a user comes back from a submenu it reprints this menu
    {
        cout << setfill('-') << setw(115) << "" << endl;
        if (username.at(0) == 'E' || username.at(0) == 'S') {
            cout << setfill('-') << setw(115) << "" << endl;
            cout << setfill('-') << setw(65) << " WELCOME TO YOUR ACCOUNT" << setfill('-') << setw(50) << "" << endl;
        }
        else {
            cout << setfill('-') << setw(65) << " WELCOME ADMINISTRATOR " << setfill('-') << setw(50) << "" << endl;
           // cout << setfill(' ') << setw(68) << CurrentSessionInfo::currUser.getFirstName() << " " << CurrentSessionInfo::currUser.getLastName() << endl;

        }
        cout << setfill('-') << setw(116) << "\n" << endl;
        cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(60) << "1. Access Library" << endl;
        cout << setfill(' ') << setw(58) << "2. View Account" << endl;
        cout << setfill(' ') << setw(51) << "0. Log out\n" << endl;
        cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

        cin >> choice;

        validChoice = true;
        switch (choice) {
        case 1:
            system("cls");
            InventoryScreen::printMenu();
            break;
        case 2:
            system("cls");
            // currUser.printMenu();
            //cout << "Need to open Account information." << endl;//view account should view list of users and allow admin to update infor via  update()
            break;
        case 0: //On Log out 
            system("cls");
            currUser.close(); //Close txt file
            return; //Changed this so it goes back to login screen instead of closing program
        default:
            system("cls");
            cout << "Invalid choice please try again" << endl;
            break;
        }
    }
  
}

//login() allows user to login to borrow books if they have a username and password
void Login::login() {
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

        ofstream userInfo;
        userInfo.open("currentUser.txt");

        if (!userInfo.is_open()) {
            cout << "File open was not successful";
        }
        //userInfo << username << endl;
        userInfo.close();      
        userHomeMenu();
       
        system("cls");
        return;
    }
   
}

//guest() allows user to be a guest and use material from the library for 2 hours
void Login::guest() {
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

// TODO: reformat using User classes & sub-classes
// DO NOT FORGET!! Add exception handling in these classes!!!!!
void Login::registration() {
    string libID, password, id, fName, lName, address, phoneNum, email;
    int choice;
    char pos;

    // Get user type first...
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

    CurrentSessionInfo::currUser.setFirstName();
    CurrentSessionInfo::currUser.setLastName();

    //check that information entered is correct, if it is save to file if it is not, enter new information  
    //FIXME write switch to allow user to pick which part is incorrect and only update that?
    // TODO : Change this part to store data into MainLogin Vector instead of file
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
            read.close();
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

// Limit first and last name to less than 20 letters and only allow letters
// FIXME not working yet.
bool Login::isValidName(string &name) {
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
 
// Asks for address information
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

#endif // !MAINLOGIN_CPP