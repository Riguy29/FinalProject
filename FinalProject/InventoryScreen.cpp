#ifndef INVENTORYSCREEN_CPP
#define INVENTORYSCREEN_CPP
#include "InventoryScreen.h"

vector<LibraryMedia*> InventoryScreen::mediaToCheckout;
string InventoryScreen::recordTxtFile;
void InventoryScreen::AddMedia()
{
	int choice =0;
	bool isValid = true;
	Book* book;
	Newspaper* newspaper;
	ConferenceJournal* journal;
	
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
		system("cls");

		switch (choice)
		{
		case 0:
			return;
		case 1:
			book = new Book();
			book->SetTitle();
			book->SetMediaType(LibraryMedia::book);
			book->SetAuthors();
			book->SetPublishers();
			book->SetCategory();
			book->SetSubCategory();
			book->SetInventoryCount();
			book->SetDoner();
			book->SetISBN();
			book->SetPrice();
			CurrentSessionInfo::mediaList.push_back(book);
			system("cls");
			cout << "New Book added!" << endl;
			break;
		case 2:
			newspaper = new Newspaper();
			newspaper->SetTitle();
			newspaper->SetMediaType(LibraryMedia::newspaper);
			newspaper->SetCategory();
			newspaper->SetSubCategory();
			newspaper->SetInventoryCount();
			newspaper->SetDoner();
			//newspaper->SetPublishRate();
			break;
		case 3:
			//journal = new ConferenceJournal(); 
			//journal->Set
			break;
		case 4:
			//periodicals
		default:
			break;
		}
	} while (true);



}
void InventoryScreen::SearchForMedia()
{
	system("cls");	
	int choice;
	bool validChoice = false;
	do {
		system("cls");
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

		ifstream user;
		string username;
		user.open("currentUser.txt");

		if (!user.is_open()) {
			cout << "File open was not successful";
		}
		user >> username;
		user.close();

		if (username.at(0) == 'M') {// if user isAdmin
			cout << setfill(' ') << setw(61) << "6. Search By Course" << endl;
			cout << setfill(' ') << setw(60) << "7. Search By Price" << endl;
			cout << setfill(' ') << setw(73) << "8. Search By Publisher Address\n" << endl;
			//CurrentSessionInfo::SetAdmin(true);
		}
		cout << setfill(' ') << setw(58) << "Enter Your Choice:\t";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 0:
			return;
			break;
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
	bool validChoice;
	
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

		if (username.at(0) == 'M') {
			cout << setfill(' ') << setw(57) << "3. Add Media" << endl;
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
			//if (isGuest) {
				cout << "Enter your name: " << endl;
				getline(cin, fullName);
				system("cls");
			//}
			cout << setfill(' ') << setw(50)<< fullName << ", Ready for checkout?" << endl;
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
		
	} while (true);
	
}
void InventoryScreen::SearchByTitle() 
{
	string searchTitle;
	cout << "Enter the title of the media you are looking for" << endl;
	cin >> searchTitle;

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
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
		
	}


}
void InventoryScreen::SearchByAuthor() 
{
	string searchAuthor;
	cout << "Enter the author of the media you are looking for" << endl;
	cin >> searchAuthor;

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
		cout << "No Matching Media Found";
		return;
	}
	else {
		PrintMatchingMedia(matchingList);
	}
}
void InventoryScreen::SearchByDepartment() 
{
	string searchDep;
	cout << "Enter the Department of the media you are looking for" << endl;
	cin >> searchDep;
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
		if (choice == 0) return;
		else if (mediaList.at(choice - 1) != NULL) {
			//Open up Media interaction menu
			MediaInteractionMenu(mediaList.at(choice - 1));
		}
		else cout << "Invalid Selection, try again" << endl;

		

	} while (true); //MAKE THIS NOT A WHILE TRUE
}

void InventoryScreen::MediaInteractionMenu(LibraryMedia* selectedMedia) {
	cout << "Selected Media";
	selectedMedia->ToString();
	cout << setfill('-') << setw(115) << "" << endl;
	cout << setfill('-') << setw(115) << "" << endl;
	cout << setfill('-') << setw(116) << "\n" << endl;
	cout << setfill(' ') << setw(68) << "What would you like to do?\n" << endl;

	//if(selectedMedia available quantity > 0){
	cout << setfill(' ') << setw(54) << "1. Add to cart " << endl; //FIXME: Make this buy if they are guest, if they are no copies and they are guest then print 
   //}else{
   // cout<<"Media not available"<<endl;
   // }
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
			//if(!isGuest){
			//FIXME:: If normal user add to cart, unless no inventory then call, if guest only buy
			//MediaID.push_back(selectedMedia.GetMediaID());
			// }
			//else{ // if (isGuest){
			/*MediaPrice.push_back(selectedMedia.GetPrice());
			MediaTitle.push_back(selectedMedia.GetTitle());
			{
				ofstream buyList("PurchaseList.txt", ios::in | ios::out);
				if (!buyList.is_open()) {
					cout << "File not opened successfully" << endl;
				}
				ostream_iterator<string> out_iterator(buyList, "\n");
				copy(MediaTitle.begin(), MediaTitle.end(), out_iterator);
				ostream_iterator<double> output_iterator(buyList, "\n");
				copy(MediaPrice.begin(), MediaPrice.end(), output_iterator);
				buyList.close();
			}
			*/
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
	} while (choice != 1 || choice != 2); //If the user enter numbers other than 1 or 2
	//confirm media y/n
	//if y then deduct from inventory count add books to user vector of checked out books
	//print list of books with return date
}
#endif // !INVENTORYSCREEN_CPP