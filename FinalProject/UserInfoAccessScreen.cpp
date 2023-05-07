#include "UserInfoAccessScreen.h"

void UserInfoAccessScreen::printMainMenu()
{
	bool goBack = false;
	string choice;
	system("cls");
	do
	{
		cout << "0.Return" << endl;
		cout << "1.View Account" << endl;
		if (CurrentSessionInfo::currUser.getLibID() == 1000) { //If admin
			cout << "2. Find User" << endl;
		}

		getline(cin, choice);

		if (choice == "0") {
			goBack = true;
		}
		else if (choice == "1") {
            printUserDataMenu();
		}
        else if (choice == "2" && CurrentSessionInfo::currUser.getLibID() == 1000) {
            SearchForUsers();
        }
        else {
            system("cls");
            cout << "Invalid Input" << endl;
        }
	} while (!goBack);
}

void UserInfoAccessScreen::printUserDataMenu()
{
    int accountChoice;
    bool valid = false;

    do {

        cout << setfill('-') << setw(117) << "" << endl;
        cout << setfill('-') << setw(50) << " CURRENT USER: " << CurrentSessionInfo::currUser.getFirstName() << " " << CurrentSessionInfo::currUser.getLastName()
            << " " << setfill('-') << setw(52 - (CurrentSessionInfo::currUser.getFirstName().size())) << "" << endl;

        cout << setfill('-') << setw(117) << "" << endl;
        cout << endl;

        cout << setfill(' ') << setw(75) << "Select from the options below:\n" << endl;
        cout << setfill(' ') << setw(55) << "0. Return" << endl;
        cout << setfill(' ') << setw(75) << "1. Update Personal Information" << endl;
        cout << setfill(' ') << setw(61) << "2. View My Books\n" << endl;
        cout << setfill(' ') << setw(63) << "Enter Your Choice:\t";

        cin >> accountChoice;

        switch (accountChoice) {
        case 0:
            valid = true;
            system("cls");
            break;
        case 1:
            system("cls");
            int updateChoice;
            cout << setfill(' ') << setw(70) << "What would you like to update?" << endl;
            cout << setfill(' ') << setw(56) << "0. Return" << endl;
            cout << setfill(' ') << setw(60) << "1. First Name" << endl;
            cout << setfill(' ') << setw(59) << "2. Last Name" << endl;
            cout << setfill(' ') << setw(57) << "3. Address" << endl;
            cout << setfill(' ') << setw(62) << "4. Phone Number" << endl;
            cout << setfill(' ') << setw(56) << "5. Email\n" << endl;
            cout << setfill(' ') << setw(63) << "Enter Your Choice:\t";
            cin >> updateChoice;
            switch (updateChoice) {
            case 1:
                CurrentSessionInfo::currUser.setFirstName();
                break;
            case 2:
                CurrentSessionInfo::currUser.setLastName();
                break;
            case 3:
                CurrentSessionInfo::currUser.setAddress();
                break;
            case 4:
                CurrentSessionInfo::currUser.setPhoneNumber();
                break;
            case 5:
                CurrentSessionInfo::currUser.setEmail();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "Invalid Choice" << endl;
            }

            break;
        case 2:
            //FIXME: open currentUser bookList
            cout << "Books you currently have checked out are: " << endl;
            for (CheckedoutMedia media : CurrentSessionInfo::borrowedMediaList) {
                if (media.GetUserId() == CurrentSessionInfo::currUser.getLibID()) {
                    media.PrintInfo();
                }
            }
            cout << endl;

            int returnInput;
            do {
                cout << "Press 0 to return to previous screen" << endl;
                cin >> returnInput;
            } while (returnInput != 0);
            break;
        default:
            system("cls");
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (!valid);
}

void UserInfoAccessScreen::SearchForUsers()
{
}

void UserInfoAccessScreen::CheckoutMediaInteractionMenu()
{
}
