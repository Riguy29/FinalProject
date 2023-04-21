#ifndef INVENTORYSCREEN_CPP
#define INVENTORYSCREEN_CPP
#include "InventoryScreen.h"

/*void InventoryScreen::AddMedia()
{
	int choice =0;
	bool isValid = true;
	Book book;
	Newspaper newspaper;
	ConferenceJournal journal;
	
	do
	{
		cout << "What kind of media would you like to add?" << endl;
		cout << "1. Book" << endl;
		cout << "2. Newspaper" << endl;
		cout << "3. Journal" << endl;
		cout << "4. Periodical" << endl;
		cout << "5. Return" << endl;
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
		case 5:
			return;
		default:
			break;
		}
	} while (true);



}
*/
//FIXME: the switch in second do while loop needs to be finished.  it will send to appropriate search function
void InventoryScreen::SearchForMedia()const
{
	system("cls");	
	int choice;
	bool validChoice = false;
	LibraryMedia::mediaTypes tempMediaType;
	string searchType = "ERROR";
	do{
		cout << setfill('-') << setw(115) << "" << endl;
		cout << setfill('-') << setw(115) << "" << endl; 
		cout << setfill('-') << setw(116) << "\n" << endl;
		cout << setfill(' ') << setw(68) << "What media would like to search for?\n" << endl;
		cout << setfill(' ') << setw(53) << "1. Books" << endl;
		cout << setfill(' ') << setw(58) << "2. Newspapers" << endl;
		cout << setfill(' ') << setw(56) << "3. Journals" << endl;
		cout << setfill(' ') << setw(59) << "4. Periodicals" << endl;
		cout << setfill(' ') << setw(55) << "5. Return\n" << endl;
		cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

		cin >> choice;
		validChoice = true; //Assume choice is valid
		switch (choice)
		{
		case 1:
			searchType = "Books";
			tempMediaType = LibraryMedia::book;
			validChoice = false;
			break;
		case 2:
			searchType = "Journals";
			tempMediaType = LibraryMedia::book;
			validChoice = false;
			break;
		case 3:
			searchType = "Newspapers";
			tempMediaType = LibraryMedia::book;
			validChoice = false;
			break;
		case 4:
			searchType = "Periodicals";
			tempMediaType = LibraryMedia::book;
			validChoice = false;
			break;
		case 5:
			printMenu();
			break;			
		default:
			cout << "Invalid selection, try again" << endl;
			return;
		}
	} while (validChoice);
	do {
		system("cls");
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
		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			SearchForMedia();
			break;
		default:
			cout << "Invalid selection, try again" << endl;

		}

	} while (!validChoice);
}
void InventoryScreen::printMenu()const {
	int choice =0;
	bool validChoice;
	
	system("cls");
	do
	{
		
		cout << setfill('-') << setw(115) << "" << endl;
		cout << setfill('-') << setw(115)<<"" << endl; //setw(62) <<  " INVENTORY SCREEN " << setfill('-') << setw(53) << "" << endl;
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
		//user.close();

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
			cout << setfill(' ') << setw(50)<< "Ready for checkout?" << endl;
			//checkoutBook();
			if (CurrentSessionInfo::CheckIfAdmin()) SearchForMedia();
			else cout << "Invalid selection, try again" << endl;
			break;
		case 3:
			system("cls");
			if (username.at(0) == 'M') {
				int editChoice;
				cout << setfill('-') << setw(115) << "" << endl;
				cout << setfill('-') << setw(115) << "" << endl;
				cout << setfill('-') << setw(116) << "\n" << endl;
				cout << setfill(' ') << setw(68) << "What would you like to do?\n" << endl;
				cout << setfill(' ') << setw(54) << "1. Edit Media" << endl;
				cout << setfill(' ') << setw(53) << "2. Add Media" << endl;
				cout << setfill(' ') << setw(56) << "3. Delete Media" << endl;
				cout << setfill(' ') << setw(51) << "4. Return\n" << endl;
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
			
			cout << "Invalid selection, try again" << endl;
			break;
		case 4:
			system("cls");
			return;
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
	} while (true);
	

}
/*void InventoryScreen::SearchByTitle()
void InventoryScreen::SearchByTitle(LibraryMedia::mediaTypes type)
{
	string title;
	cout << "Enter the title of the " << type << "you are looking for" << endl;
	cin >> title;
	if (type == LibraryMedia::book) {

		//Create vector of pointers that will point to the memory of matching books found in BookList();
		vector<Book*> matchingBookList;

		//Goes through Book list and checks for title that contain the user input
		//for (int i = 0; i < CurrentSessionInfo::GetBookList().size(); i++)
		//{
		//	if (CurrentSessionInfo::GetBookList().getItem(i).GetTitle().find(title) != string::npos) {
		//		Book* pNewBook = &CurrentSessionInfo::GetBookList().getItem(i);
		//		matchingBookList.push_back(pNewBook);
		//		if (matchingBookList.size() >= 5) {
		//			PrintMatchingMedia(matchingBookList);
		//		}
		//	}
		//}
		if (matchingBookList.size() == 0) {
			cout << "No Books Found";
			return;
		}
	}
	else if (type == LibraryMedia::conferenceJournal) {
		vector<ConferenceJournal> matchingJournalList;
	}


}

	while (pMedia != nullptr)
	{

	}
}*/
void InventoryScreen::PrintMatchingMedia(vector<Book*> mediaList)
{
	
	Book* selectedBook;
	int choice=0;
	do
	{
		cout << "Select a book" << endl;
		for (int i = 1; i <= mediaList.size(); i++)
		{
			cout << i << ". ";
			mediaList.at(i-1)->ToString();
			cout << endl;
		}
		cout << "6. Return" << endl;
		cin >> choice;
		if (choice == 6) return;
		else if (mediaList.at(choice - 1) != NULL) {
			selectedBook = mediaList.at(choice - 1);
			//Open up a option to edit the book
		}
		else cout << "Invalid Selection, try again" << endl;

		

	} while (true);
}


#endif // !INVENTORYSCREEN_CPP