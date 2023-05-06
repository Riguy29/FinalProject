#ifndef INVENTORYSCREEN_CPP
#define INVENTORYSCREEN_CPP
#include "InventoryScreen.h"

vector<LibraryMedia*> InventoryScreen::mediaToCheckout;
string InventoryScreen::recordTxtFile;

InventoryScreen::InventoryScreen(){}
InventoryScreen::~InventoryScreen(){}

void InventoryScreen::AddMedia()
{
	int choice =0;
	bool isValid = true;

	do
	{
		cout << setfill('-') << setw(115) << "" << endl;
		cout << setfill('-') << setw(115) << "" << endl; 
		cout << setfill('-') << setw(116) << "\n" << endl;
		cout << setfill(' ') << setw(72) << "What kind of media would you like to add?\n" << endl;
		cout << setfill(' ') << setw(54) << "0. Return" << endl;
		cout << setfill(' ') << setw(53) << "1. Books" << endl;
		cout << setfill(' ') << setw(58) << "2. Newspapers" << endl;
		cout << setfill(' ') << setw(56) << "3. Journals" << endl;
	    cout << setfill(' ') << setw(60) << "4. Periodicals\n" << endl;
		cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";
		cin >> choice;
		
		LibraryMedia* newMedia;
		if (choice == 1) newMedia = new Book();
		else if (choice == 2) newMedia = new Newspaper();
		else if (choice == 3) newMedia = new ConferenceJournal();
		else if (choice == 4) newMedia = new Periodical();
		else if (choice == 0){
			system("cls");
			return;
		}
		else {
			system("cls");
			cout << "Invalid Selection,try again" << endl;
			continue;
		}

		newMedia->SetTitle();
		newMedia->SetAuthors();
		newMedia->SetPublishers();
		newMedia->SetInventoryCount();
		newMedia->SetPrice();
		newMedia->SetCategory();
		newMedia->SetSubCategory();
		newMedia->SetDoner();

		if (choice == 1)
		{
			Book* book = dynamic_cast<Book*>(newMedia);
			book->SetMediaType(LibraryMedia::book);
			book->SetISBN();
			book->SetEdition();
			CurrentSessionInfo::mediaList.emplace_back(new Book(*book));
			delete book;
			system("cls");
			cout << "New Book Added" << endl;
		}
		else if (choice == 2) {
			Newspaper* newspaper = dynamic_cast<Newspaper*>(newMedia);
			newspaper->SetMediaType(LibraryMedia::newspaper);
			newspaper->SetPublishRate();
			CurrentSessionInfo::mediaList.emplace_back(new Newspaper(*newspaper));
			delete newspaper;
			system("cls");
			cout << "New newspaper added" << endl;
		}
		else if (choice == 3) {
			ConferenceJournal* journal = dynamic_cast<ConferenceJournal*>(newMedia);
			journal->SetMediaType(LibraryMedia::conferenceJournal);
			journal->SetDateOfConference();
			journal->SetPlaceOfConference();
			CurrentSessionInfo::mediaList.emplace_back(new ConferenceJournal(*journal));
			delete journal;
			system("cls");
			cout << "New Journal added" << endl;
		}
		else if (choice == 4) {
			Periodical* period = dynamic_cast<Periodical*>(newMedia);
			period->SetMediaType(LibraryMedia::periodical);
			period->SetPublishRate();
			CurrentSessionInfo::mediaList.emplace_back(new Periodical(*period));
			delete period;
			system("cls");
			cout << "New Periodical added" << endl;
		}
	} while (true);
}

void InventoryScreen::SearchForMedia()
{
	system("cls"); 
	int choice;
	bool validChoice = false;
	do {
		cout << setfill('-') << setw(115) << "" << endl;
		cout << setfill('-') << setw(56) << " SEARCH " << setfill('-') << setw(59) << "" << endl;
		cout << setfill('-') << setw(115) << "" << endl;
		cout << endl;
		cout << setfill(' ') << setw(51) << "0. Return" << endl;
		cout << setfill(' ') << setw(60) << "1. Search By Title" << endl;
		cout << setfill(' ') << setw(61) << "2. Search By Author" << endl;
		cout << setfill(' ') << setw(64) << "3. Search By Publisher" << endl;
		cout << setfill(' ') << setw(65) << "4. Search By Department" << endl;
		cout << setfill(' ') << setw(62) << "5. Search By Subject" << endl;
/*
		ifstream user;
		string username;
		user.open("currentUser.txt");

		if (!user.is_open()) {
			cout << "File open was not successful";
		}
		user >> username;
		user.close();
		*/
		//if (username.at(0) == 'M') {// if user isAdmin
			cout << setfill(' ') << setw(61) << "6. Search By Course" << endl;
			cout << setfill(' ') << setw(60) << "7. Search By Price" << endl;
			cout << setfill(' ') << setw(73) << "8. Search By Publisher Address\n" << endl;
			//CurrentSessionInfo::SetAdmin(true);
		//}
		cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
		system("cls");
		if (!cin) { //If they enter a a non integer value go to next loop
			cout << "Invalid selection, try again" << endl;
			continue;
		}
		switch (choice) {
		case 0:
			return;
		case 1:
			SearchByTitle();
			break;
		case 2:
			SearchByAuthor();
			break;
		case 3:
			SearchByPublisherName();
			break;
		case 4:
			SearchByDepartment();
			break;
		case 5:
			SearchBySubject();
			break;
		case 6:
			SearchForMedia();
			break;
		case 7:
			SearchByPrice();
			break;
		case 8:
			SearchByPublisherAddress();
			break;		
		default:
			cout << "Invalid selection, try again" << endl;
		}
		
	} while (!validChoice);
}
void InventoryScreen::printMenu() {
	int choice =0;
	bool validChoice = true;
	
	system("cls");
	do
	{
		cout << setfill('-') << setw(115) << "" << endl;
		cout << setfill('-') << setw(115)<<"" << endl; //setw(62) <<  " INVENTORY SCREEN " << setfill('-') << setw(53) << "" << endl;
		cout << setfill('-') << setw(116) << "\n" << endl;

		cout << setfill(' ') << setw(68) << "Select from the options below:\n" << endl;
		cout << setfill(' ') << setw(53) << "0. Return" << endl;
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
		if(GuestLogin::isGuest(false)) {// needs to be User::isAdmin(true){
		//if (username.at(0) == 'M') {
			cout << setfill(' ') << setw(56) << "3. Add Media" << endl;
		}
		user.close();
		
		cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

		cin >> choice;
		validChoice = true; //Assume choice is valid
		string fullName;

		switch (choice)
		{
		case 0:

			//Delete all pointers and then clear vector
			for (LibraryMedia* mediaPointer : mediaToCheckout)
			{
				delete mediaPointer;
			}
			mediaToCheckout.clear();
			system("cls");
			return;
		case 1:
			system("cls");
			SearchForMedia();			
			break;
		case 2: //If a user is not an admin and selects 2, make choice invlaid
			system("cls");
			if (GuestLogin::isGuest(true)) {
				GuestLogin::buy();
			}
			
			//CheckoutBook();
			//if (CurrentSessionInfo::CheckIfAdmin()) SearchForMedia();
			//else cout << "Invalid selection, try again" << endl;
			
			break;
		case 3: //If a user is not an admin and selects 2, make choice invlaid
			system("cls");
			/*
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
				case 2:
					system("cls");
					//addMedia
					break;
				case 3:
					system("cls");
					//deleteMedia
					break;
				case 4:
					system("cls");
					return;
				default:
					cout << "Invalid selection, try again" << endl;
				}
			}
			
				system("cls");
				//return;				
				//cout << "needs to go back to patronMenu in MainLogin" << endl;
			
			
			//cout << "Invalid selection, try again" << endl;
			*/
			AddMedia();
			break;
		default:
			cout << "Invalid selection, try again" << endl;
			break;
		}
		
	} while (validChoice);
	
}

void InventoryScreen::SearchByTitle() 
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string searchTitle;
	cout << "Enter the title of the media you are looking for" << endl;
	getline(cin, searchTitle);

	//Create vector of pointers that will point to the memory of matching books found in BookList();
	vector<LibraryMedia*> matchingList;

	//Goes through Book list and checks for title that contain the user input

	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetTitle().find(searchTitle) != string::npos) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found" <<endl;
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}

}
void InventoryScreen::SearchByAuthor() 
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string searchAuthor;
	cout << "Enter the author of the media you are looking for" << endl;
	getline(cin,searchAuthor);

	//Create vector of pointers that will point to the memory of matching books found in BookList();
	vector<LibraryMedia*> matchingList;

	//Goes through Book list and checks for title that contain the user input

	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetSearchString(0).find(searchAuthor) != string::npos) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::SearchByDepartment() 
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string searchDep;
	cout << "Enter the Department of the media you are looking for" << endl;
	getline(cin, searchDep);
	vector<LibraryMedia*> matchingList;//Create vector of pointers that will point to the memory of matching books found in BookList();
	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)//Goes through Book list and checks for title that contain the user input
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetCategory().find(searchDep) != string::npos) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::SearchBySubject() 
{
	string searchSub;
	cout << "Enter the Department of the media you are looking for" << endl;
	cin >> searchSub;
	vector<LibraryMedia*> matchingList;//Create vector of pointers that will point to the memory of matching books found in BookList();
	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)//Goes through Book list and checks for title that contain the user input
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetSubCategory().find(searchSub) != string::npos) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::SearchByPublisherName()
{
	string searchName;
	cout << "Enter the publisher's name of the media you are looking for" << endl;
	cin >> searchName;
	vector<LibraryMedia*> matchingList;//Create vector of pointers that will point to the memory of matching books found in BookList();
	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)//Goes through Book list and checks for title that contain the user input
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetSearchString(1).find(searchName) != string::npos) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::SearchByPrice()
{
	double searchPrice;
	cout << "Enter the Price of the media you are looking for" << endl;
	cin >> searchPrice;
	vector<LibraryMedia*> matchingList;//Create vector of pointers that will point to the memory of matching books found in BookList();
	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)//Goes through Book list and checks for title that contain the user input
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetPrice() == searchPrice) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::SearchByPublisherAddress()
{
	string searchAdd;
	cout << "Enter the publisher's address of the media you are looking for" << endl;
	cin >> searchAdd;
	vector<LibraryMedia*> matchingList;//Create vector of pointers that will point to the memory of matching books found in BookList();
	for (int i = 0; i < CurrentSessionInfo::mediaList.size(); i++)//Goes through Book list and checks for title that contain the user input
	{
		if (CurrentSessionInfo::mediaList.at(i)->GetSearchString(2).find(searchAdd) != string::npos) {
			matchingList.push_back(CurrentSessionInfo::mediaList.at(i));
			if (matchingList.size() >= 5) {
				PrintMatchingMedia(matchingList); //If we get more than 5 matches only return the top 5
			}
		}
	}
	if (matchingList.size() == 0) { //IF we dont find any media, print out statement and then return
		system("cls");
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::PrintMatchingMedia(vector<LibraryMedia*> mediaList) 
{
	
	LibraryMedia* selectedMedia;
	int choice=0;
	bool valid = true;
	do
	{
		cout << "Select a media" << endl;
		for (int i = 1; i <= mediaList.size(); i++)
		{
			cout << i << ". ";
			mediaList.at(i-1)->ToString();
			cout << endl;
		}
		cout << "0. Return" << endl;
		cin >> choice;
		if (choice == 0) {
			system("cls");
			return;
		}
		else if (mediaList.at(choice - 1) != NULL) {
			//Open up Media interaction menu
			MediaInteractionMenu(mediaList.at(choice - 1));
		}
		else cout << "Invalid Selection, try again" << endl;

		

	} while (valid); 
}

void InventoryScreen::MediaInteractionMenu(LibraryMedia* selectedMedia) {
	cout << "Selected Media";
	selectedMedia->ToString();
	cout << setfill('-') << setw(115) << "" << endl;
	cout << setfill('-') << setw(115) << "" << endl;
	cout << setfill('-') << setw(116) << "\n" << endl;
	cout << setfill(' ') << setw(68) << "What would you like to do?\n" << endl;

	if (selectedMedia->GetInventoryCount() > 0) {
	cout << setfill(' ') << setw(54) << "1. Add to cart " << endl;  
   }
	else{
		cout << setfill(' ') << setw(54) << "No Copies Available" << endl;
		return;
	}
	//if(isAdmin) {
	//FIXME:: Only print these options if current user is admin
	cout << setfill(' ') << setw(53) << "2. Update Media" << endl;
	cout << setfill(' ') << setw(56) << "3. Delete Media" << endl;
	//END ADMIN SECTION
	//}
	cout << setfill(' ') << setw(51) << "0. Return\n" << endl;
	cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";

	int choice;
	do
	{
		choice = -1;
		switch (choice) {
		case 1:
			{
			if(GuestLogin::isGuest(true)){
				ofstream clearBuyList("PurchaseList.txt", ios::trunc);//open file to clear it and then close
				clearBuyList.close();

				ofstream buyList("PurchaseList.txt", ios::in | ios::out | ios::app);//open file to write to it

				if (buyList.is_open()) {
					buyList << selectedMedia->GetTitle() << selectedMedia->GetPrice();
					//buyList << selectedMedia->GetPrice();
					buyList.close();
				}
				//mediaToCheckout->SetInventoryCount(mediaToCheckout->GetInventoryCount() - 1);
				else {
					cout << "File not opened successfully" << endl;
				}		
			 }
			else {
				//FIXME:: If normal user add to cart, unless no inventory then call
			//MediaID.push_back(selectedMedia.GetMediaID());
			}

			return;
			}
			
			break;
		case 2:
			//CHECK IF ADMIN
			//if(!isAdmin){
			//cout << "Invalid choice." << endl;
			//}else{
			//UpdateMedia();
			break;
		case 3:
			//CHECK IF ADMIN DON'T ALLOW IF NOT ADMIN
			//if(!isAdmin){
			//cout << "Invalid choice." << endl;
			//}else{
			// delete selected MediaID
			//}
			break;
		case 0:
			return;
		}

	} while (choice != -1);
	
}

void InventoryScreen::ConfirmMediaCheckout() {
	system("cls");
	for (LibraryMedia* media : mediaToCheckout) {
		media->ToString();
		cout << endl;
	}

	int choice;
	do
	{
		cout << "Does this look correct?" << endl;
		cout << "1.Yes" << endl;
		cout << "2.No, clears cart" << endl;

		cin >> choice;
		if (choice == 1) {
			//Checkout Media
		}
		else if (choice == 2) {
			//Clears cart and returns
		}
	} while (choice != 1 && choice != 2); //If the user enter numbers other than 1 or 2
	//confirm media y/n
	//if y then deduct from inventory count add books to user vector of checked out books
	//print list of books with return date
}

void InventoryScreen::EditMediaDataMenu(LibraryMedia* selectedMedia) {
	int choice;
	do
	{
		cout << "Editing: ";
		selectedMedia->ToString();
		cout << endl;

		cout << "0. Return" << endl;
		cout << "1. Change Title" << endl;
		cout << "2. Change Authors" << endl;
		cout << "3. Change Publishers" << endl;
		cout << "4. Change Category" << endl;
		cout << "5. Change SubCateogory" << endl;
		cout << "6. Change Price" << endl;
		cout << "7. Change Doner" << endl;
		cout << "8. Change Iventory Count" << endl;

		switch (selectedMedia->GetMediaType())
		{
		case LibraryMedia::book:
			break;
		case LibraryMedia::conferenceJournal:
			break;
		case LibraryMedia::newspaper:
			break;
		case LibraryMedia::periodical:
			break;
		default:
			break;
		}
	} while (true);
}
#endif // !INVENTORYSCREEN_CPP