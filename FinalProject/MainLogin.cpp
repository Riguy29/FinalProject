#ifndef MAINLOGIN_CPP
#define MAINLOGIN_CPP

#include "MainLogin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <random>

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
        cout << "Have a great Day!" << endl;
        system("PAUSE");
        system("cls");
        printMenu();
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
    string id;
    string pass;
    bool exists = false;
    cout << "Please log in or " << endl;
    cout << "Press 1 to return to Main Menu." << endl;
    cout << endl;

    ifstream userpass("userpass.txt");
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

    while (userpass.is_open()) {
        getline(userpass, id);
        getline(userpass, pass);

        //if (userpass >> id >> pass) {//check to see if password exists
        if (id == username && pass == password) {
            exists = true;
        }
        // }

        userpass.close();
    }
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
    else {
        system("cls");
        cout << "\nLogin not successful.  Please try again.";
        system("PAUSE");
        system("cls");
        //login(); 

    }

}
//guest() allows user to be a guest and use material from the library for 2 hours
void Login::guest()const {
    string gName;
    string media;
    vector<string>guestBorrowList;
    int choice;
    //cout << "Enter your full name: \n" << endl;
    //getline(cin, gName);
    cout << "Press 1 to return to Main Menu." << endl;
    cout << "Enter your name: \n" << endl;
    cin >> gName;
    cout << endl;
    if (!gName._Equal("1")) {
        cout << "What will you be borrowing today?\n (press d when finished)\n" << endl;
        while (!media._Equal("d")) {
            cin >> media;
            guestBorrowList.push_back(media);
        }

        system("cls");
        //FIXME: LINK TIME FUNCTION AND ADD TIME TO COUT
        cout << "Thank you " << gName << "! You are borrowing " << endl;
        for (int i = 0; i < guestBorrowList.size() - 1; i++) {
            cout << guestBorrowList.at(i) << endl;
        }
        cout << "\nThe time is ? ? Time ? ? Please return items by ? ? ? Time ? ? ?" << endl;
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
        cout << "Press 1 to get password." << endl;
        cout << "Press 2 to go to return to Main Menu. " << endl;
        cin >> option2;



        switch (option2) {

        case 1:
            system("cls");
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
    case 2:
        system("cls");
        int option3;
        cout << "\nForgot Username?: No worries! " << endl;
        cout << "Press 1 to get username." << endl;
        cout << "Press 2 to go to return to Main Menu. " << endl;
        cin >> option3;
        switch (option3) {
        case 1:
            system("cls");
            cout << "Enter the email associated with your account." << endl;
            cin >> fEmail;

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
                    printMenu();
                    break;
                default:
                    system("cls");
                    cout << "Invalid Choice...Please Try Again...\n" << endl;
                    break;
                }
            }
            break;
        case 2:
            system("cls");
            printMenu();
            break;
        default:
            system("cls");
            cout << "Invalid Choice...Please Try Again...\n" << endl;
            break;
        }
    case 3:
        system("cls");
        printMenu();
        break;
    default:
        system("cls");
        cout << "Invalid Choice...Please Try Again...\n" << endl;
        break;
    }
}

string Login::randomPass() {
    //srand(time(0));
    int passLength = 10;
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
//registration() allows user to register for an account if they don't have one already
void Login::registration()const {
    string fName, lName, address, phoneNum, email, id, libID, password;
    char pos;

    int choice;
    ofstream file;
    file.open("records.txt", ios::in | ios::app);
    ofstream userpassList;
    userpassList.open("userpass.txt", ios::in | ios::app);

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
    cout << "\nEnter your phone number: \t" << endl;
    getline(cin, phoneNum);
    cout << "\nEnter your email: \t" << endl;
    getline(cin, email);
    cout << endl;
    cout << "staff member M\nemployee E\nstudent S \t" << endl;
    cout << "Enter your position(M/E/S)" << endl;
    cin >> pos;
    switch (pos) {
    case 'M':
    case 'm':
        cout << "\nEnter your staff ID: \t" << endl;
        libID = "M" + lName + randomLibID();
        password = randomPass();
        break;
    case 'E':
    case 'e':
        cout << "\nEnter your employee ID: \t" << endl;
        libID = "E" + lName + randomLibID();
        password = randomPass();
        break;
    case 'S':
    case 's':
        cout << "\nEnter your student ID: \t" << endl;
        libID = "S" + lName + randomLibID();
        password = randomPass();
        break;
    default:
        cout << "Not a valid entry." << endl;

    }
    cin.ignore();
    getline(cin, id);
    cout << endl;
    char correct;
    cout << "Is the information correct? Y/N" << endl;
    cout << "Name: " << fName << " " << lName << "\nAddress: " << address << "\nPhone: " << phoneNum << "\nEmail: " << email
        << "\nPosition: " << pos << "\nID: " << id << endl;
    cin >> correct;
    switch (correct) {
    case 'Y':
    case'y':
        if (file.is_open()) {
            //file << "Name: " << fName << " " << lName << "\tAddress: " << address << "\tPhone: " << phoneNum << "\tEmail: " << email
              //  << "\tPosition: " << pos << "\tID: " << id << "\tLibrary Login: " << libID << "\tPassword: " << password << "\t" << endl;
            file << "Name: " << fName << " " << lName << "\nAddress: " << address << "\nPhone: " << phoneNum << "\nEmail: " << email
                << "\nPosition: " << pos << "\nID: " << id << "\nLibraryID: " << libID << "\nPassword: " << password << endl;
            file << endl;
            file.close();
        }
        if (userpassList.is_open()) {
            userpassList << libID << "\t" << password << endl;
            userpassList.close();
        }

        system("cls");
        cout << "\nRegistration is successful!" << endl;
        cout << "\nYour Library ID is: \t" << libID << endl;
        cout << "\nYour password is: \t" << password << endl;
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
            printMenu();
            break;
        default:
            system("cls");
            cout << "Invalid Choice...Please Try Again...\n" << endl;
            break;
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
#endif // !MAINLOGIN_CPP
