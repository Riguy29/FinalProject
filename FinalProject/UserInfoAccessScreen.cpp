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

//Might not even use this
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

    //When a users logs in get there currently checkedout books and store them in a vector
    for (CheckedoutMedia media : CurrentSessionInfo::borrowedMediaList) {
        if (media.GetUserId() == CurrentSessionInfo::currUser.getLibID()) {
            usersCheckedoutMedia.push_back(media);
        }
    }
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
            usersCheckedoutMedia.clear();
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
            DisplayCheckedoutMedia();
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
