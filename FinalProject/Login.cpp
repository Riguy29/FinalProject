#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include "Login.h"
#include <iostream>
#include <string>

using namespace std;

Login::Login() : Login("", ""){} //default constructor initialized to empty strings

Login::Login(string userN, string userP) : username(userN), password(userP){}

Login::Login(Login& l) : username(l.username), password(l.password){}

Login::~Login(){}

void Login::print()const {

}
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

bool Login::isValid()const {
   /* string num;
    bool alphavalid;
    bool numvalid;

    do {
        cout << "Enter your username." << endl;
        cin >> num;
        cout << endl;

        } while (cin.get() != null);

        for (int i = 0; i < 3; i++) {
            if (!isalpha(num.at(i))) {
                alphavalid = false;
            }
            else {
                alphavalid = true;
            }
        }

        for (int i = 3; i < 7; i++) {
            if (!isdigit(num.at(i))) {
                numvalid = false;
            }
            else {
                numvalid = true;
            }
        }

        if (alphavalid && numvalid) {
            cout << "valid" << endl;
        }
        else {
            cout << "invalid" << endl;
        }
*/      
    return true;
	}

#endif // !LOGINSCREEN_H
