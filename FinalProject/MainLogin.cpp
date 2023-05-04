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
        system("cls");
        date.printDate();
        cout << setfill('-') << setw(115) << "" << endl;
        cout << setfill('-') << setw(56) << " LIBRARY LOGIN " << setfill('-') << setw(59) << "" << endl;
        cout << setfill('-') << setw(115) << "" << endl;
        cout << setfill(' ') << setw(53) << "WELCOME!\n" << endl;
        cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(66) << "1. Login to Your Account" << endl;
        cout << setfill(' ') << setw(56) << "2. Guest Login" << endl;
        cout << setfill(' ') << setw(65) << "3. Register for Account" << endl;
        cout << setfill(' ') << setw(49) << "4. Exit" << endl;
        cout << setfill(' ') << setw(108) << "5. List all Registered Accounts (Please remove before submission)\n" << endl;
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
        case 5:
            system("cls");

            for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
                CurrentSessionInfo::userList.at(i)->printData();
            }

            system("PAUSE");
            cin.get();

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

// Called to register a user and emplace said user to the end of the userList vector
void Login::registration() {
    User* tmpUsr;
    char pos;

    // Reference InventoryScreen.cpp AddMedia function on how to determine what obj they are
    // Get user type first...
    do {
        cout << "Enter your position(M/E/S)" << endl;
        cout << "Staff member M\nEmployee E\nStudent S \t" << endl;
        cin >> pos;
    } while (pos != 'M' && pos != 'E' && pos != 'S' && pos != 'm' && pos != 'e' && pos != 's');

    //check positon and set object type
    if (pos == 'M') tmpUsr = new Staff();
    else if (pos == 'E') tmpUsr = new FacultyMember();
    else tmpUsr = new Student();

    tmpUsr->setFirstName();
    tmpUsr->setLastName();
    tmpUsr->setAddress();
    tmpUsr->setPhoneNumber();
    tmpUsr->setEmail();
    tmpUsr->setLibID(1000 + CurrentSessionInfo::userList.size());

    if (pos == 'M') {
        Staff* st = dynamic_cast<Staff*>(tmpUsr);
        st->setUserType(User::staff);
        st->setID();
        st->setPassword();
        CurrentSessionInfo::userList.emplace_back(new Staff(*st));
        delete st;
        system("cls");
        cout << "New Staff User Added" << endl;
    }
    else if (pos == 'E') {
        FacultyMember* fm = dynamic_cast<FacultyMember*>(tmpUsr);
        fm->setUserType(User::facultyMember);
        fm->setID();
        fm->setPassword();
        CurrentSessionInfo::userList.emplace_back(new FacultyMember(*fm));
        delete fm;
        system("cls");
        cout << "New Faculty Member User Added" << endl;
    } 
    else {
        Student* st = dynamic_cast<Student*>(tmpUsr);
        st->setUserType(User::student);
        st->setID();
        st->setPassword();
        CurrentSessionInfo::userList.emplace_back(new Student(*st));
        delete st;
        system("cls");
        cout << "New Student User Added" << endl;
    }

    cout << endl;

    char correct;

    //check that information entered is correct, if it is save to file if it is not, enter new information  
    cout << "Is the information correct? Y/N" << endl;
    CurrentSessionInfo::userList.back()->printData();
    cin >> correct;

    if (correct == 'N') {
        CurrentSessionInfo::userList.pop_back();
        registration();
    }
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
    
    return false;
    read.close();
}


 
/*
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
*/

#endif // !MAINLOGIN_CPP