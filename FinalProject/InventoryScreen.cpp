#ifndef INVENTORYSCREEN_CPP
#define INVENTORYSCREEN_CPP
#include "InventoryScreen.h"
#include "tinyxml2.h"
using namespace tinyxml2;

/*void InventoryScreen::AddMedia()
{
	//XMLDocument inventoryXML;
	////FIXME: Right now we are just assuming it will load right
	//XMLError eResult = inventoryXML.LoadFile("InventoryRecord.xml"); 
	int choice =0;
	bool isValid = true;
	LibraryMedia book;
	Newspaper newspaper;
	ConferenceJournal journal;
	
	do
	{
		cout << "What kind of media would you like to add?" << endl;
		cout << "1. Book" << endl;
		cout << "2. Newspaper" << endl;
		cout << "3. Journal" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			book.SetTitle();
			book.SetISBN();
			book.SetPrice();
			break;
		case 2:
			newspaper.SetTitle();
			newspaper.SetISBN();
		default:
			break;
		}
	} while (true);



}
*/
void InventoryScreen::SearchForMedia()const
{
	system("cls");
	
	int choice;
	bool validChoice = false;
do{

	//FIXME
	cout << setfill('-') << setw(115) << "" << endl;
	cout << setfill('-') << setw(56) << " SEARCH " << setfill('-') << setw(59) << "" << endl;
	cout << setfill('-') << setw(115) << "" << endl;
	cout << endl;
	cout << setfill(' ') << setw(60) << "1. Search By Title" << endl;
	cout << setfill(' ') << setw(61) << "2. Search By Author" << endl;
	cout << setfill(' ') << setw(64) << "3. Search By Publisher" << endl;
	cout << setfill(' ') << setw(65) << "4. Search By Department" << endl;
	cout << setfill(' ') << setw(62) << "5. Search By Subject" << endl;

	ifstream user;
	string username;
	user.open("currentUser.txt");

	if (!user.is_open()) {
		cout << "File open was not successful";
	}
	user >> username;
	user.close();

	if (username.at(0) == 'M') {
		cout << setfill(' ') << setw(61) << "6. Search By Course" << endl;
		cout << setfill(' ') << setw(60) << "7. Search By Price" << endl;
		//CurrentSessionInfo::SetAdmin(true);
	}
	cout << setfill(' ') << setw(53) << "8. Return\t\n" << endl;
	cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";
	cin >> choice;
	
		validChoice = true; //Assume choice is valid
		switch (choice)
		{
		case 1:
			//SearchByTitle();
			break;
		case 2:
			//SearchByAuthor();
			break;
		case 3:
			//SearchByPublisher
			break;
		case 4:
			//SearchByDepartment
			break;
		case 5:
			//SearchBySubject
			break;
		case 6:
			//SearchByCourse
			break;
		case 7:
			//SearchByPrice
			break;
		case 8:
			system("cls");
			printMenu();
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
	} while (!validChoice);
	//If search find items, return the top 5 items
	
}
void InventoryScreen::printMenu()const {
	int choice =0;
	bool validChoice;
	do
	{
		
		cout << setfill('-') << setw(115) << "" << endl;
		cout << setfill('-') << setw(62) << " INVENTORY SCREEN " << setfill('-') << setw(53) << "" << endl;
		cout << setfill('-') << setw(116) << "\n" << endl;
		cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
		cout << setfill(' ') << setw(59) << "1. Search Media" << endl;
		cout << setfill(' ') << setw(55) << "2. Checkout" << endl;

		ifstream user;
		string username;
		user.open("currentUser.txt");

		if (!user.is_open()) {
			cout << "File open was not successful";
		}
		user >> username;
		user.close();

		if (username.at(0) == 'M') {
			cout << setfill(' ') << setw(57) << "3. Edit Media" << endl;
			cout << setfill(' ') << setw(54) << "4. Return\n" << endl;

		}
		else {
			cout << setfill(' ') << setw(54) << "3. Return\n" << endl;

		}
		user.close();
		cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

		cin >> choice;
		validChoice = true; //Assume choice is valid
		switch (choice)
		{
		case 1:
			system("cls");
			SearchForMedia();
			break;
		case 2: //If a user is not an admin and selects 2, make choice invlaid
			system("cls");
			cout << "Ready for checkout?" << endl;
			//checkoutBook();
			break;
		case 3:
			system("cls");
			if (username.at(0) == 'M') {
				int editChoice;
				cout << setfill(' ') << setw(50) << "1. Edit Media" << endl;
				cout << setfill(' ') << setw(50) << "2. Add Media" << endl;
				cout << setfill(' ') << setw(50) << "3. Delete Media" << endl;
				cout << setfill(' ') << setw(50) << "4. Return\n" << endl;
				cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";
				cin >> editChoice;
				switch (editChoice) {
				case 1:
					system("cls");
					//editMedia();
					break;
				case2:
					system("cls");
					//addMedia
					break;
				case3:
					system("cls");
					//deleteMedia
					break;
				case 4:
					system("cls");
					printMenu();
					break;
				default:
					cout << "Invalid selection, try again" << endl;
				}
			}
			else {
				system("cls");
				return;
				//cout << "needs to go back to patronMenu in MainLogin" << endl;
			}
			
		case 4:
			system("cls");
			//cout << "needs to go to adminMenu in MainLogin" << endl;
			//adminMenu();
			//exit(0);
			return;
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
	} while (true);
	

}
/*void InventoryScreen::SearchByTitle()
{
	string title;
	cout << "Enter the title of the media you are looking for" << endl;
	cin >> title;

	XMLDocument inventoryXML;
	XMLElement* pRootElement = inventoryXML.RootElement();
	XMLElement* pInvetory = pRootElement->FirstChildElement("inventory");
	XMLElement* pMedia = pInvetory->FirstChildElement("media");

	while (pMedia != nullptr)
	{

	}
}*/

#endif // !INVENTORYSCREEN_CPP