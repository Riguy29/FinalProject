/*
    This is the main login for the library.  From this screen a user will be able to choose whether they would like
    to login as a member or a guest, register as a new member, retrieve forgotten username or password or exit the system.
*/
#ifndef MAINLOGIN_CPP
#define MAINLOGIN_CPP

#include "MainLogin.h"

using namespace std;

// Default constructor
Login::Login() {} 
Login::Login(Login& l) {}
Login::~Login() {}

// printMenu() prints the menu options for the login screen
void Login::printMenu() {
    int choice;
    bool valid = true;

    do {
        system("cls");
        date.printDate();
        cout << setfill('-') << setw(117) << "" << endl;
        cout << setfill('-') << setw(63) << right << " LIBRARY LOGIN " << setfill('-') << setw(54) << "" << endl;
        cout << setfill('-') << setw(117) << "" << endl;
        cout << setfill(' ') << setw(61) << right << "WELCOME!\n" << endl;
        cout << setfill(' ') << setw(72) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(66) << "1. Login to Your Account" << endl;
        cout << setfill(' ') << setw(56) << "2. Guest Login" << endl;
        cout << setfill(' ') << setw(65) << "3. Register for Account" << endl;
        cout << setfill(' ') << setw(50) << "4. Exit\n" << endl;
        cout << setfill(' ') << setw(60) << "Enter Your Choice:\t";

        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            CurrentSessionInfo::isGuest = false;
            login();
            break;
        case 2:
            system("cls");
            CurrentSessionInfo::isGuest = true; //Set isGuest to true if a guest logins in
            InventoryScreen::printMenu();
            break;
        case 3:
            registration();
            break;
        case 4:
            system("cls");
            CurrentSessionInfo::SaveAllData(); //Before we exit save all our data
            //Then destory all pointers so we dont leak memory
            for (LibraryMedia* mediaP : CurrentSessionInfo::mediaList) {
                delete mediaP;
            }
            for (User* userP : CurrentSessionInfo::userList) {
                delete userP;
            }
            exit(0);
            break;
        /* Illegal
        case 5:
            system("cls");

            cout << "Total Users in vector: " << CurrentSessionInfo::userList.size() << endl;

            for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
                CurrentSessionInfo::userList.at(i)->printData();
            }

            system("pause");

            break;
        */
        default:
            system("cls");
            cout << "Invalid Choice...Please Try Again...\n" << endl;
            break;
        }
    } while (valid);
 }

// login() allows user to login to borrow books if they have a username and password
void Login::login() {
    int id;
    string password;
    string line;

    cout << "Please log in or " << endl;
    cout << "Press 0 to return to Main Menu." << endl;
    cout << endl;

    do {
        cout << "\nEnter your Library ID: \t" << endl;
        cin >> id;
        if (id != 0) {
            cout << "\nEnter your password: \t" << endl;
            cin >> password;
            if (password._Equal("0")) {
                system("cls");
                printMenu();
            }
        } else {
            system("cls");
            printMenu();
        }

      } while (isLoginValid(id, password) != true);

      system("cls");
      cout << endl;

      cin.clear();
      cin.ignore();

      // Check if the user is admin (in our case just the first account)
      if (CurrentSessionInfo::currUser.getLibID() == 1000) {
          UserInfoAccessScreen::printAdminMenu();
      }
      else {
          system("cls");
          UserInfoAccessScreen::printUserDataMenu();
      }
}


// Called to register a user and emplace said user to the end of the userList vector
void Login::registration() {
    User* tmpUsr;
    char pos;

    // Reference InventoryScreen.cpp AddMedia function on how to determine what obj they are
    // Get user type first...
    do {
        system("cls");
        cout << "Enter your position(M/E/S)" << endl;
        cout << "Staff member M\nEmployee E\nStudent S\t" << endl;
        cin >> pos;
    } while (pos != 'M' && pos != 'E' && pos != 'S' && pos != 'm' && pos != 'e' && pos != 's');

    //check positon and set object type
    if (pos == 'M' || pos == 'm') tmpUsr = new Staff();
    else if (pos == 'E' || pos == 'e') tmpUsr = new FacultyMember();
    else tmpUsr = new Student();

    tmpUsr->setFirstName();
    tmpUsr->setLastName();
    tmpUsr->setAddress();
    tmpUsr->setPhoneNumber();
    tmpUsr->setEmail();
    tmpUsr->setPassword();
    tmpUsr->setLibID(1000 + CurrentSessionInfo::userList.size());

    if (pos == 'M') {
        Staff* st = dynamic_cast<Staff*>(tmpUsr);
        st->setUserType(User::staff);
        st->setID();

        cout << "Is the information correct? Y/N" << endl;
        st->printData();

        do {
            pos = getchar();
            if (pos == 'N' || pos == 'n') {
                delete st;
                registration();
            }
            else if (pos != 'Y' && pos != 'y') {
                cout << "Please Enter only Y/N for input!" << endl;
            }
        } while (pos != 'N' && pos != 'n' && pos != 'Y' && pos != 'y');

        CurrentSessionInfo::userList.emplace_back(new Staff(*st));

        delete st;
        system("cls");
        cout << "New Staff User Added" << endl;
    }
    else if (pos == 'E') {
        FacultyMember* fm = dynamic_cast<FacultyMember*>(tmpUsr);
        fm->setUserType(User::facultyMember);
        fm->setID();

        cout << "Is the information correct? Y/N" << endl;
        fm->printData();

        do {
            pos = getchar();
            if (pos == 'N' || pos == 'n') {
                delete fm;
                registration();
            }
            else if (pos != 'Y' && pos != 'y') {
                cout << "Please Enter only Y/N for input!" << endl;
            }
        } while (pos != 'N' && pos != 'n' && pos != 'Y' && pos != 'y');

        CurrentSessionInfo::userList.emplace_back(new FacultyMember(*fm));

        delete fm;
        system("cls");
        cout << "New Faculty Member User Added" << endl;
    } 
    else {
        Student* st = dynamic_cast<Student*>(tmpUsr);
        st->setUserType(User::student);
        st->setID();

        cout << "Is the information correct? Y/N" << endl;
        st->printData();

        do {
            pos = getchar();
            if (pos == 'N' || pos == 'n') {
                delete st;
                registration();
            }
            else if (pos != 'Y' && pos != 'y') {
                cout << "Please Enter only Y/N for input!" << endl;
            }
        } while (pos != 'N' && pos != 'n' && pos != 'Y' && pos != 'y');

        CurrentSessionInfo::userList.emplace_back(new Student(*st));

        delete st;
        system("cls");
        cout << "New Student User Added" << endl;
    }

    cout << endl;

    CurrentSessionInfo::SaveUserData();

    // Empty and repopulate vector, because saving it causes an issue with the last added object otherwise
    CurrentSessionInfo::userList.clear();
    CurrentSessionInfo::LoadUserData<FacultyMember>("Faculty.txt");
    CurrentSessionInfo::LoadUserData<Staff>("Staff.txt");
    CurrentSessionInfo::LoadUserData<Student>("Students.txt");
}

//validate username and password match to login
bool Login::isLoginValid(int &inUser, string &inPass) {

    for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
        if (CurrentSessionInfo::userList.at(i)->getLibID() == inUser) {
            if (CurrentSessionInfo::userList.at(i)->getPassword() == inPass) {
                CurrentSessionInfo::currUser = *CurrentSessionInfo::userList.at(i);
                return true;
            }
        }
    }

    system("cls");
    cout << "\nLibrary ID or Password not found. Please try again, or enter 0 to return." << endl;
    
    return false;
}

#endif // !MAINLOGIN_CPP