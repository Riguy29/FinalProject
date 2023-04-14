#ifndef ADMINMENU_CPP
#define ADMINMENU_CPP
#include "AdminMenu.h"
#include <iostream>
#include <string>	

using namespace std;

//AdminMenu::AdminMenu(){}
AdminMenu::~AdminMenu(){}

void AdminMenu::addMedia()const{}
void AdminMenu::updateMedia()const{}
void AdminMenu::removeMedia()const{}
void AdminMenu::viewMedia()const{}
void AdminMenu::search()const{}
void AdminMenu::viewAccount()const{}
void AdminMenu::printMenu()const{
    int choice;
    cout << "************************************\n" << endl;
    cout << "********* WELCOME ADMINISTRATOR! ********\n" << endl;//<< FIXME...get current user name \n" << endl;
    cout << "************************************\n" << endl;
    cout << "Select from the options below \n" << endl;
    cout << "1. Add Media\n" << endl;
    cout << "2. Update Media\n" << endl;
    cout << "3. Delete Media\n" << endl;
    cout << "4. View Media\n" << endl;
    cout << "5. Search Media\n" << endl;
    cout << "6. View Member Accounts\n" << endl;
    cout << "7. Exit\n" << endl;
    cout << "Enter Your Choice: \n" << endl;
    cin >> choice;

    switch (choice) {

    case 1:
        addMedia();
        break;
    case 2:
        updateMedia();
        break;
    case 3:
        removeMedia();
        break;
    case 4:
        viewMedia();
        break;
    case 5:
        search();
        break;
    case 6:
        viewAccount();
        break;
    case 7:
        exit(0);
        break;
    default:
        cout << "Invalid Choice...Please Try Again...\n" << endl;
    }
   
}


#endif // !ADMINMENU_CPP


