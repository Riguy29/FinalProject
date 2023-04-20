#ifndef ADMINMENU_CPP
#define ADMINMENU_CPP
#include "AdminMenu.h"
#include <iostream>
#include <string>	
#include <iomanip>

using namespace std;

AdminMenu::AdminMenu(){}
AdminMenu::~AdminMenu(){}

void AdminMenu::addMedia()const{}
void AdminMenu::updateMedia()const{}
void AdminMenu::removeMedia()const{}
void AdminMenu::viewMedia()const{}
void AdminMenu::search()const{}
void AdminMenu::viewAccount()const{}
void AdminMenu::printMenu()const{
    int choice;
    cout << setfill('-') << setw(120) << "" << endl;
    cout << setfill('-') << setw(65) << " WELCOME ADMINISTRATOR " << setfill('-') << setw(60) << "" << endl;
    cout << setfill('-') << setw(120) << "\n" << endl;
    cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
    cout << setfill(' ') << setw(56) << "1. Add Media\n" << endl;
    cout << setfill(' ') << setw(59) << "2. Update Media\n" << endl;
    cout << setfill(' ') << setw(59) << "3. Delete Media\n" << endl;
    cout << setfill(' ') << setw(57) << "4. View Media\n" << endl;
    cout << setfill(' ') << setw(59) << "5. Search Media\n" << endl;
    cout << setfill(' ') << setw(67) << "6. View Member Accounts\n" << endl;
    cout << setfill(' ') << setw(51) << "7. Exit\n" << endl;
    cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

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


