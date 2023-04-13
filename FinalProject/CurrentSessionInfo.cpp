#include "CurrentSessionInfo.h"


//I guess because this is a static variable we have to define it outside of our .h file, idk thats what the internet told me and now it works so
bool CurrentSessionInfo::isUserAdmin = false;
LinkedList<Book> CurrentSessionInfo::bookList = LinkedList<Book>();
LinkedList<ConferenceJournal> CurrentSessionInfo::journalList = LinkedList<ConferenceJournal>();
LinkedList<Newspaper> CurrentSessionInfo::newspaperList = LinkedList<Newspaper>();
LinkedList<Periodical> CurrentSessionInfo::periodicalList = LinkedList<Periodical>();


void CurrentSessionInfo::SetAdmin(bool isAdmin)
{
	isUserAdmin = isAdmin;
}

bool CurrentSessionInfo::CheckIfAdmin()
{
	return isUserAdmin;
}

void CurrentSessionInfo::LoadInventory()
{
	fstream stream;
	stream.open("BookRecord.txt", ios::in | ios::out | ios::binary);
	if (stream.is_open()) {
		cout << "Opened Book Record txt" << endl;
		if (stream.peek() == EOF) { //Checking if file is empty and if it is creating dummy data to fill the file
			cout << "File empty, filling with data";
			LinkedList<string> Authors;
			LinkedList<Publisher> publishers;
			//Authors.insertItem("J.R.R Tolkien");
			Book book1("Lord Of The Rings", Authors, publishers, LibraryMedia::book, "Fantasy", "High Fantasy", 5, 25.34, "123123123", 3);
			//Authors.clearList();
			//Authors.insertItem("Suzane Collins");
			Book book2("The Hunger Games", Authors, publishers, LibraryMedia::book, "Distyopia", "", 2, 20.00, "52311235", 1);
			stream.write(reinterpret_cast<char*>(&book1), sizeof(Book));
			stream.write(reinterpret_cast<char*>(&book2), sizeof(Book));		
		}
		//string* readData = NULL;
		//stream.readsome
		stream.close();
	}
	else cout << "Error opening Book Record txt";

	
}

LinkedList<Book> CurrentSessionInfo::GetBookList()
{
	return bookList;
}
