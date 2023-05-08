#include "UserInfoAccessScreen.h"
vector<reference_wrapper<CheckedoutMedia>> UserInfoAccessScreen::usersCheckedoutMedia;

void UserInfoAccessScreen::DisplayCheckedoutMedia()
{
    system("cls");
    bool goBack = false;
    int choice;
    do {
        cout << " Enter 0 to go back" << endl;
        cout << "Books you currently have checked out are: " << endl;
        for (int i = 1; i <= usersCheckedoutMedia.size(); i++)
        {
            cout << i << ". ";
            usersCheckedoutMedia.at(i - 1).get().PrintInfo();
            cout << endl;
        }
        try
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
            if (!cin) throw(1);
            if (choice == 0) {
                system("cls");
                goBack = true;
            }
            else if ((choice - 1) < usersCheckedoutMedia.size()) { //If a users selects a valid 
                //Open up Media interaction menu
                bool wasMediaReturned = false;
                CheckoutMediaInteractionMenu(usersCheckedoutMedia.at(choice - 1).get(), wasMediaReturned);
                if (wasMediaReturned) goBack = true;
            }
            else {
                throw(1);
            }
        }
        catch (int errorCode)
        {
            system("cls");
            if (errorCode == 1) cout << "Error, invalid input" << endl;
        }


    } while (!goBack);
}

// Essentially the "User Menu"
void UserInfoAccessScreen::printUserDataMenu()
{
    //When a users logs in get there currently checkedout books and store them in a vector
    for (CheckedoutMedia media : CurrentSessionInfo::borrowedMediaList) {
        if (media.GetUserId() == CurrentSessionInfo::currUser.getLibID()) {
            usersCheckedoutMedia.push_back(media);
        }
    }
    int accountChoice;
    bool valid = false;
    
    int userLibID = CurrentSessionInfo::currUser.getLibID();

    do {
        string fName = CurrentSessionInfo::currUser.getFirstName();
        string lName = CurrentSessionInfo::currUser.getLastName();

        cout << setfill('-') << setw(117) << "" << endl;
        cout << setfill('-') << setw(62) << right << " CURRENT USER: " << fName << " " << lName
            << " " << setfill('-') << setw(45) << "" << endl;

        cout << setfill('-') << setw(117) << "" << endl;
        cout << endl;

        cout << setfill(' ') << setw(75) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(54) << "0. Logout" << endl;
        cout << setfill(' ') << setw(75) << "1. Update Personal Information" << endl;
        cout << setfill(' ') << setw(61) << "2. View My Books" << endl;
        cout << setfill(' ') << setw(65) << "3. Search Inventory\n" << endl;
        cout << setfill(' ') << setw(63) << "Enter Your Choice:\t";

        cin >> accountChoice;

        switch (accountChoice) {
        case 0:
            valid = true;
            usersCheckedoutMedia.clear();
            system("cls");
            break;
        case 1:
            system("cls");
            userLibID = CurrentSessionInfo::currUser.getLibID();

            for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
                if (CurrentSessionInfo::userList.at(i)->getLibID() == userLibID) {
                    string fName = CurrentSessionInfo::userList.at(i)->getFirstName();
                    string lName = CurrentSessionInfo::userList.at(i)->getLastName();
                    updateUserInfo(userLibID, i); //Commented this out because it was undefined
                    CurrentSessionInfo::currUser = *CurrentSessionInfo::userList.at(i);
                }
            }

            break;
        case 2:
            DisplayCheckedoutMedia();
            break;
        case 3:
            system("cls");
            InventoryScreen::printMenu();
            break;
        default:
            system("cls");
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (!valid);
}

// Prints the main admin menu
void UserInfoAccessScreen::printAdminMenu() {
    string choice;
    bool goBack = false;

    system("cls");

    // Using a while true loop so that when a user comes back from a submenu it reprints this menu
    do {
        cout << setfill('-') << setw(117) << "" << endl;
        cout << setfill('-') << setw(65) << " WELCOME ADMIN " << setfill('-') << setw(52) << "" << endl;
        cout << setfill('-') << setw(117) << "" << endl;
        cout << endl;

        cout << setfill(' ') << setw(73) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(53) << "0. Log out" << endl;
        cout << setfill(' ') << setw(62) << "1. Access Inventory" << endl;
        cout << setfill(' ') << setw(67) << "2. View Member Accounts\n" << endl;
        cout << setfill(' ') << setw(61) << "Enter Your Choice:\t";

        getline(cin, choice);

        if (choice == "1") {
            system("cls");
            InventoryScreen::printMenu();
        }
        else if (choice == "2") {
            system("cls");
            int userLibID;

            cout << "Total Users: " << CurrentSessionInfo::userList.size() << endl;

            for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
                CurrentSessionInfo::userList.at(i)->printData();
            }
            cout << endl;

            int adminChoice;
            cout << setfill(' ') << setw(55) << "0. Return" << endl;
            cout << setfill(' ') << setw(70) << "1. Update Member Account" << endl;
            cout << setfill(' ') << setw(70) << "2. Delete Member Account" << endl;
            cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

            cin >> adminChoice;
            switch (adminChoice) {
            case 0:
                system("cls");
                break;
            case 1:
                system("cls");
                cout << "Enter Account Library ID you wish to modify: ";

                cin >> userLibID;

                for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
                    if (userLibID == CurrentSessionInfo::userList.at(i)->getLibID()) {
                        updateUserInfo(userLibID, i);
                        break;
                    }
                }
                break;
            case 2:
                system("cls");
                deleteUserAcc();
                break;
            default:
                cout << "Invalid Choice" << endl;
            }
        }
        else if (choice == "0") {
            system("cls");
            goBack = true;
        }
        else if (choice == "") {
            system("cls");
        }
        else {
            system("cls");
            cout << "Invalid choice please try again" << endl;
        }
    } while (!goBack);
}

// Update user account information
void UserInfoAccessScreen::updateUserInfo(int userLibID, int i) {
    system("cls");

    int userUpdateChoice;

    cout << setfill(' ') << setw(70) << "What would you like to update?" << endl;
    cout << setfill(' ') << setw(56) << "0. Return" << endl;
    cout << setfill(' ') << setw(60) << "1. First Name" << endl;
    cout << setfill(' ') << setw(59) << "2. Last Name" << endl;
    cout << setfill(' ') << setw(57) << "3. Address" << endl;
    cout << setfill(' ') << setw(62) << "4. Phone Number" << endl;
    cout << setfill(' ') << setw(56) << "5. Email\n" << endl;
    cout << setfill(' ') << setw(63) << "Enter Your Choice:\t";
    cin >> userUpdateChoice;
    switch (userUpdateChoice) {
    case 1:
        CurrentSessionInfo::userList.at(i)->setFirstName();
        system("cls");
        break;
    case 2:
        CurrentSessionInfo::userList.at(i)->setLastName();
        system("cls");
        break;
    case 3:
        CurrentSessionInfo::userList.at(i)->setAddress();
        system("cls");
        break;
    case 4:
        CurrentSessionInfo::userList.at(i)->setPhoneNumber();
        system("cls");
        break;
    case 5:
        CurrentSessionInfo::userList.at(i)->setEmail();
        system("cls");
        break;
    case 0:
        system("cls");
        break;
    default:
        cout << "Invalid Choice" << endl;
    }
}


void UserInfoAccessScreen::CheckoutMediaInteractionMenu(CheckedoutMedia& selectedMedia, bool& mediaReturned)
{
    system("cls");
    int choice;
    bool goBack = false;
    do
    {
        selectedMedia.PrintInfo();
        cout << "0. Go Back" << endl;
        cout << "1. Renew" << endl;
        cout << "2. Return" << endl;

        cin >> choice;
        if (!cin) continue;
        switch (choice)
        {
        case 0:
            system("cls");
            goBack = true;
            break;
        case 1:
            selectedMedia.Renew();
            break;
        case 2:
            selectedMedia.ReturnMedia();

            //Reloads the users media list because an object was removed
            usersCheckedoutMedia.clear();
            for (CheckedoutMedia media : CurrentSessionInfo::borrowedMediaList) {
                if (media.GetUserId() == CurrentSessionInfo::currUser.getLibID()) {
                    usersCheckedoutMedia.push_back(media);
                }
            }
            mediaReturned = true;
            goBack = true;
            system("cls");
            cout << "Returned Media";
            break;
        default:
            break;
        }
    } while (!goBack);
}
// Delete user account
void UserInfoAccessScreen::deleteUserAcc() {
    int userLibID;
    char choice;

    // Make sure user cant delete currently logged in account
    do {
        cout << "Enter Library ID of account to delete: " << endl;
        cin >> userLibID;
        system("cls");
        if (userLibID == CurrentSessionInfo::currUser.getLibID()) {
            cout << setfill(' ') << setw(80) << "Cannot delete currently logged in account!" << endl;
        }

    } while (userLibID == CurrentSessionInfo::currUser.getLibID());

    for (int i = 0; i < CurrentSessionInfo::userList.size(); i++) {
        if (CurrentSessionInfo::userList.at(i)->getLibID() == userLibID) {
            string fName = CurrentSessionInfo::userList.at(i)->getFirstName();
            string lName = CurrentSessionInfo::userList.at(i)->getLastName();
            cout << setfill(' ') << setw(58) << "Current User Selected: " << fName << " " << lName << "\n" << endl;
            cout << setfill(' ') << setw(80) << "Are you sure you wish to delete this account?" << endl;
            cout << setfill(' ') << setw(58) << "Enter Y/N to continue:\t";

            do {
                cin >> choice;
            } while (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n');

            if (choice == 'Y' || choice == 'y') {
                CurrentSessionInfo::userList.erase(CurrentSessionInfo::userList.begin() + i);
                CurrentSessionInfo::SaveUserData();

                CurrentSessionInfo::userList.clear();
                CurrentSessionInfo::LoadUserData<FacultyMember>("Faculty.txt");
                CurrentSessionInfo::LoadUserData<Staff>("Staff.txt");
                CurrentSessionInfo::LoadUserData<Student>("Students.txt");

                system("cls");
                cout << "User with Library ID " << userLibID << " has been deleted!" << endl;
                system("pause");
            }

            break;
        }
    }
}
