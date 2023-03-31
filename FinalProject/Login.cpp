#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include "Login.h"
#include "AdminMenu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

Login::Login() : Login("", ""){} //default constructor initialized to empty strings

Login::Login(string userN, string userP) 
    : username(userN), password(userP){}

Login::Login(Login& l) : username(l.username), password(l.password){}

Login::~Login(){}


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
    cout << "************LIBRARY LOGIN***********\n" << endl;
    cout << "************************************\n" << endl;
    cout << "WELCOME!\n" << endl;
    cout << "How would you like to login today?\n" << endl;
    cout << "1. Login\n" << endl;
    cout << "2. Guest\n" << endl;
    cout << "3. New User\n" << endl;
    cout << "4. Forgot login\n" << endl;
    cout << "5. Exit\n" << endl;
    cout << "Enter Your Choice: \n" << endl;
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
        cout << "You are loged out." << endl;
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
    cout << "Press 1 to return to Main Menu." << endl;
    cout << "Please log in. " << endl;
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
    ifstream userpass("records.txt");

    while (userpass >> id >> pass) {//check to see if password exists
        if (id == username && pass == password) {
            exists = true;
        }
    }
    userpass.close();

    if (true) {
        system("cls");
             cout << username << " Login Successful!" << endl;
            //FIXME: IF LOGIN MATCHES ADMIN LOGIN GO TO ADMIN MENU ELSE GO TO PATRON LOGIN

        }
        else {
        system("cls");
            cout << "\nLogin not successful.  Please try again.";
            login();
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
        for (int i = 0; i < guestBorrowList.size()-1; i++) {
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

//registration() allows user to register for an account if they don't have one already
void Login::registration()const {
    string regName;
    string regEmail;
    string regUser;
    string regPass;
    string regid;
    string regpass;
    int choice;
    cout << "Press 1 to return to Main Menu." << endl;
    cout << "\nEnter your name: \t" << endl;
    cin >> regName;    
    if (regName._Equal("1")){// || regEmail._Equal("1") || regUser._Equal("1") || regPass._Equal("1")) {
        system("cls");
            printMenu();
    }
    else {
        cout << "\nEnter your email: \t" << endl;
        cin >> regEmail;
        cout << "\nEnter your username: \t" << endl;
        cin >> regUser;
        cout << "\nEnter your password: \t" << endl;
        cin >> regPass;

        ofstream f1("records.txt", ios::binary);// \ ios::out)

        f1 << regName << ' ' << regEmail << ' '<< regUser << ' ' << regPass << endl;
        system("cls");
        cout << "\nRegistration is successful!" << endl;
        cout << "\nPress 1 to return to login" << endl;
        cout << "\nPress 2 to exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            login();
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
}

/*
isValid checks to see if username and password is correct
*/
//bool Login::isValid(string username, string password)const {
  //  return true;
	//}

#endif // !LOGINSCREEN_H
