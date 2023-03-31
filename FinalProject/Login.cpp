#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include "Login.h"
#include "AdminMenu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

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
    cout << "4. Exit\n" << endl;
    cout << "Enter Your Choice: \n" << endl;
    cin >> choice;

    switch (choice) {

    case 1:
        login();
        break;
    case 2:
        guest();
        break;
    case 3:
        registration();
        break;
    case 4:
        cout << "You are loged out." << endl;
        break;
    default:
        cout << "Invalid Choice...Please Try Again...\n" << endl;
    }
    

}
//login() allows user to login to borrow books if they have a username and password
void Login::login()const {
    string username;
    string password;
    string id;
    string pass;
    bool exists = false;

    cout << "Please log in. " << endl;
    cout << "\nEnter your username: \t" << endl;
    cin >> username;
    cout << "\nEnter your password: \t" << endl;
    cin >> password;

    ifstream userpass("records.txt");

    while (userpass >> id >> pass) {//check to see if password exists
        if (id == username && pass == password) {
            exists = true;
        }
    }
    userpass.close();

    if (true) {
        //system("cls");
             cout << username << " Login Successful!" << endl;
            //FIXME: IF LOGIN MATCHES ADMIN LOGIN GO TO ADMIN MENU ELSE GO TO PATRON LOGIN

        }
        else {
            cout << "\n Login not successful.  Please try again.";
        }
    
}
//guest() allows user to be a guest and use material from the library for 2 hours
void Login::guest()const {
    string gName;    
    string media;
    int choice;
    cout << "Enter your full name: \n" << endl;
    getline(cin, gName);
    cout << endl;
    cout << "What will you be borrowing today?\n" << endl;
    getline(cin, media);
    cout << endl;
    //FIXME: LINK TIME FUNCTION AND ADD TIME TO COUT
    cout << "Thank you " << gName << "! You are borrowing " << media << ". The time is ? ? Time ? ? Please return items by ? ? ? Time ? ? ? \n" << endl;   
    
    do {
        cout << "press 1 to return to Main Menu" << endl;
        cout << "press 2 to exit" << endl;
        cin >> choice;
    } while (choice != 1 && choice != 2);
    if (choice == 1) {
        printMenu();
    }
    else {
        cout << "You have exited.Thank you!"<< endl;
    }
}
//forgot() has users enter their username and retreives their password if they have one on in the file records.txt
void Login::forgot()const {
    int option;
    bool exists = false;
    string forgotUser;
    string forgotPass;
    string fID;
    string fPass;
    
    cout << "\n Forgot Password?: No worries! " << endl;
    cout << "\n Press 1 to get password." << endl;
    cout << "Press 2 to go to back to login. " << endl;
    cin >> option;
    ifstream f2("records.txt");

    switch (option) {
        
    case 1:  

        cout << "\n Enter username: " << endl;
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
            cout << "\n Your account is found!" << endl;
            cout << "\n  Your password is :  " << fPass << endl;
            cout << "\n press 1 to return to login" << endl;
            cout << "\n press 2 to exit" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                login();
                break;
            case 2:
                cout << "Thank you!  Have a great day." << endl;
                break;
            }

        }
        else {// username not found
            int choice;
            cout << "\n Sorry, no account found." << endl;
            cout << "\n press 1 to return to Main Menu" << endl;
            cout << "\n press 2 to exit" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                printMenu();
                break;
            case 2:
                cout << "Thank you!  Have a great day." << endl;
                break;
            }
        }
    break;
    case 2:
    login();
    break;
    }
}

//registration() allows user to register for an account if they don't have one already
void Login::registration()const {
    string regUser;
    string regPass;
    string regid;
    string regpass;
    int choice;
    cout << "Enter your username: \t" << endl;
    cin >> regUser;
    cout << "\nEnter your password: \t" << endl;
    cin >> regPass;

    ofstream f1("records.txt", ios::binary);// \ ios::out)
    f1 << regUser << ' ' << regPass << endl;
    cout << "\n Registration is successful!"<< endl;
    cout << "\n press 1 to return to login" << endl;
    cout << "\n press 2 to exit" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        login();
        break;
    case 2:
        cout << "Thank you!  Have a great day." << endl;
        break;
    }
}
/*
isValid checks to see if username and password is correct
*/
//bool Login::isValid(string username, string password)const {
  //  return true;
	//}

#endif // !LOGINSCREEN_H
