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

using namespace std;

Login::Login() : Login("", "") {} //default constructor initialized to empty strings

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

void Login::TimeFunction() {
    // current date/time based on current system
    time_t now = time(0);

    // Char array for ctime_s to get time to compile properly using C++ 20
    // This char array holds the string of what the current time is
    char str[26];

    // Get the current time and convert to string, storing it in the str char array
    ctime_s(str, sizeof str, &now);

    cout << str << endl;
}

//printMenu() prints the menu options for the login screen
void Login::printMenu()const {
    int choice;
    cout << "************************************\n" << endl;
    cout << "*********   LIBRARY LOGIN   ********\n" << endl;
    cout << "************************************\n" << endl;
    cout << "               WELCOME!\n" << endl;
    cout << "Select from the options below \n" << endl;
    cout << "1. Member Login\n" << endl;
    cout << "2. Guest Login\n" << endl;
    cout << "3. Register\n" << endl;
    cout << "4. Forgot Login\n" << endl;
    cout << "5. Exit\n" << endl;
    //cout << "Enter Your Choice: \n" << endl;
    cin >> choice;

    switch (choice) {

    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        guest();
        break;
    case 3:
        system("cls");
        registration();
        break;
    case 4:
        system("cls");
        forgot();
        break;
    case 5:
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

//login() allows user to login to borrow books if they have a username and password
void Login::login()const {
    string username;
    string password;

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
       TimeFunction();
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
//forgot() has users enter their username and retreives their password if they have one on in the file records.txt
// if user forgot username they can enter their email and retreive it that way.
void Login::forgot()const {
    int option;
    int option2;
    bool exists = false;
    string forgotUser;
    string forgotPass;
    string fID;
    string fPass;
    string email;
    string fEmail;

    cout << "\nPress 1 if you forgot your password.\nPress 2 if you forgot your username.\nPress 3 to return to main menu" << endl;
    cin >> option;

    ifstream f2("records.txt");

    switch (option) {
    case 1:
        system("cls");
        cout << "\nForgot Password?: No worries! " << endl;
       
        cout << "Press 1 to return to Main Menu. " << endl;
        
        do {
            cout << "\nEnter username: " << endl;
            cin >> fID;

            while (f2 >> fID >> fPass) {//file records has an ID and Password that matches
                if (fID == forgotUser) {
                    exists = true;
                }
            }

            f2.close();

            //if the username was found in the file, print password
            if (true) {
                int choice;
                cout << "\nYour account is found!" << endl;
                cout << "\nYour password is :  " << fPass << endl;
                cout << "\nPress 1 to return to Main Menu" << endl;
                cout << "Press 2 to exit" << endl;
                cin >> choice;
                switch (choice) {
                case 1:
                    system("cls");
                    printMenu();
                    break;
                case 2:
                    system("cls");
                    cout << "Thank you!  Have a great day." << endl;
                    printMenu();
                    break;
                default:
                    system("cls");
                    cout << "Invalid Choice...Please Try Again...\n" << endl;
                    break;
                }

            }
            else {// username not found
                int choice2;
                cout << "\nSorry, no account found." << endl;
                cout << "\nPress 1 to return to Main Menu" << endl;
                cout << "Press 2 to exit" << endl;
                cin >> choice2;
                switch (choice2) {
                case 1:
                    system("cls");
                    printMenu();
                    break;
                case 2:
                    system("cls");
                    cout << "Thank you!  Have a great day." << endl;
                    printMenu();
                    break;
                default:
                    system("cls");
                    cout << "Invalid Choice...Please Try Again...\n" << endl;
                    break;
                }
            }
            break;
        } while (!fID._Equal("1"));
            system("cls");
            cout << "Thank you!  Have a great day." << endl;
            system("PAUSE");
            system("cls");
            printMenu();
            
            break;
    case 2://forgot username; enter email
        system("cls");
        //int option3;
        cout << "\nForgot Username?: No worries! " << endl;        
        cout << "Press 1 to go to return to Main Menu. " << endl;
  

        do {
            cout << "\nEnter the email associated with your account." << endl;
            cin.ignore();
            getline(cin, fEmail);
        } while (isEmailValid(fEmail) != true && (!fEmail._Equal("1")));

        if (fEmail._Equal("1")) {
            system("cls");         
            printMenu();
        }
        else {

            while (f2 >> fID >> fEmail) {//file records has an ID and Password that matches
                if (fEmail == email) {
                    exists = true;
                }
            }

            f2.close();
            //if the username was found in the file, print password
            if (true) {
                int choice3;
                cout << "\nYour account is found!" << endl;
                cout << "\nYour username is :  " << fID << endl;
                cout << "\nPress 1 to return to Main Menu" << endl;
                cout << "Press 2 to exit" << endl;
                cin >> choice3;
                switch (choice3) {
                case 1:
                    system("cls");
                    printMenu();
                    break;
                case 2:
                    system("cls");
                    cout << "Thank you! Have a great day." << endl;
                    system("PAUSE");
                    printMenu();
                    break;
                default:
                    system("cls");
                    cout << "Invalid Choice...Please Try Again...\n" << endl;
                    break;
                }

            }
            else {// username not found
                int choice4;
                cout << "\nSorry, no account found." << endl;
                cout << "\nPress 1 to return to Main Menu" << endl;
                cout << "Press 2 to exit" << endl;
                cin >> choice4;
                switch (choice4) {
                case 1:
                    system("cls");
                    printMenu();
                    break;
                case 2:
                    system("cls");
                    cout << "Thank you! Have a great day." << endl;
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

    case 3:
        system("cls");
        printMenu();
        break;
    default:
        system("cls");
        cout << "Invalid Choice...Please Try Again...\n" << endl;
        system("PAUSE");
        break;

        }
        }
}

//registration() allows user to register for an account if they don't have one already
void Login::registration()const {
    string fName, lName, address, phoneNum, email, id, libID, password;
    char pos;
    int choice;

    cout << "Press 1 to return to Main Menu or" << endl;
    cout << "\nEnter your first name: \t" << endl;
    cin.ignore();
    getline(cin, fName);
    if (fName._Equal("1")) {
        system("cls");
        printMenu();
    }

    cout << "\nEnter your last name: \t" << endl;
    getline(cin, lName);
    cout << "\nEnter your address: \t" << endl;
    cin.ignore();
    getline(cin, address);    
    
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

    do {//check positon and issue username and password
        cout << "Enter your position(M/E/S)" << endl;
        cout << "Staff member M\nEmployee E\nStudent S \t" << endl;
        cin >> pos;
        positionCheck(pos);     
    } while (pos != 'M' && pos != 'E' && pos != 'S' && pos != 'm' && pos != 'e' && pos != 's');
    positionCheck(pos);
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
    // srand(time(0));
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
    //srand(time(0));
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
      
//check position using switch
void Login::positionCheck(char &pos) {
    string libID;
    string password;
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
}
 
#endif // !MAINLOGIN_CPP