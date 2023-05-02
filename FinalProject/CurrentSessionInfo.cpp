#include "CurrentSessionInfo.h"

//I guess because this is a static variable we have to define it outside of our .h file, idk thats what the internet told me and now it works so
bool CurrentSessionInfo::isUserAdmin = false;
vector<Publisher> CurrentSessionInfo::pubList;
vector<Author> CurrentSessionInfo::authorList;
vector<LibraryMedia*> CurrentSessionInfo::mediaList;
vector<User*> CurrentSessionInfo::userList;
User CurrentSessionInfo::currUser;
string CurrentSessionInfo::BOOK_FILE_PATH = "BookRecord.txt";
string CurrentSessionInfo::NEWS_FILE_PATH = "NewspaperRecord.txt";
string CurrentSessionInfo::JOURNAL_FILE_PATH = "JournalRecord.txt";
string CurrentSessionInfo::PERIODICAL_FILE_PATH = "PeriodicalRecord.txt";
string CurrentSessionInfo::USER_FILE_PATH = "Users.txt";

void CurrentSessionInfo::GenerateDummyData()
{
	fstream stream;
	stream.open("PublisherRecord.txt", ios::binary | ios::out);
	if (stream.is_open()) {
		Publisher p1(1, "Good House", "1804 High Road", "GHouse@gmail.com");
		Publisher p2(2, "Bad House", "1804 Low Road", "LHouse@gmail.com");
		stream.write(reinterpret_cast<char*> (&p1), sizeof(Publisher));
		stream.write(reinterpret_cast<char*> (&p2), sizeof(Publisher));
	}
	stream.clear();
	stream.close();
	stream.open("AuthorRecord.txt", ios::binary | ios::out);

	if (stream.is_open()) {
		Author a1(1, "JRR Tolkien");
		Author a2(2, "Susane Collins");
		stream.write(reinterpret_cast<char*> (&a1), sizeof(Author));
		stream.write(reinterpret_cast<char*> (&a2), sizeof(Author));
	}
	stream.close();
	stream.open("BookRecord.txt", ios::binary | ios::out);

	if (stream.is_open()) {
		Book b1(1, "Lord of the Rings", 24, "Fiction", "Fantasy", 5, "Riley Jr", "5123523", 1);
		Book b2(2, "The Hunger Games", 15, "Fiction", "Dystopia", 5, "Amber", "89239123", 3);
		stream.write(reinterpret_cast<char*> (&b1), sizeof(Book));
		stream.write(reinterpret_cast<char*> (&b2), sizeof(Book));
	}

	stream.close();
	stream.open("NewspaperRecord.txt", ios::binary | ios::out);

	if (stream.is_open()) {
		Newspaper n1(3,"The Daily Planet",15,"News","Superhero News",10,"Clark Kent",Newspaper::weekly);
		stream.write(reinterpret_cast<char*> (&n1), sizeof(Newspaper));
	}
	stream.close();

	stream.open("PeriodicalRecord.txt", ios::binary | ios::out);

	if (stream.is_open()) {
		Periodical p1(4, "Monthy Science",25,"Science","Cool Science",2,"John Wick", Periodical::monthly);
		stream.write(reinterpret_cast<char*> (&p1), sizeof(Periodical));
	}
	stream.close();
}

vector<LibraryMedia*> CurrentSessionInfo::GetLibraryInventory()
{
	return mediaList;
}

vector<User*> CurrentSessionInfo::GetUsersVector() 
{
	return userList;
}

void CurrentSessionInfo::LoadAllData()
{
	LoadData<Publisher>("PublisherRecord.txt", pubList);
	LoadData<Author>("AuthorRecord.txt", authorList);

	LoadMediaData<Book>("BookRecord.txt");
	LoadMediaData<Newspaper>("NewspaperRecord.txt");
	LoadMediaData<Periodical>("PeriodicalRecord.txt");

	LoadUserData<User>("Users.txt");

	//LoadData<ConferenceJournal>("JournalRecord.txt");
}

void CurrentSessionInfo::SaveAllData()
{
	SaveData<Publisher>("PublisherRecord.txt", pubList);
	SaveData<Author>("AuthorRecord.txt", authorList);

	SaveData();
}

template<typename T>
void CurrentSessionInfo::LoadData(string fileName, vector<T>& list)
{
	fstream inStream;
	inStream.open(fileName, ios::binary | ios::in);
	T temp;
	if (inStream.is_open()) {
		while (inStream.read(reinterpret_cast<char*>(&temp), sizeof(T)))
		{
			list.push_back(temp);
		}
	}
	else cout << "Error: Could not load data, make sure filepath is correct";
	inStream.close();
}

// Loads Media Data
template<typename T>
void CurrentSessionInfo::LoadMediaData(string fileName)
{
	fstream inStream;
	inStream.open(fileName, ios::binary | ios::in);
	T temp;

	if (inStream.is_open()) {
		while (inStream.read(reinterpret_cast<char*>(&temp), sizeof(T)))
		{
			mediaList.emplace_back(new T(temp));
		}
	}

	else cout << "Error: Could not load media data, make sure filepath is correct";
	inStream.close();
}

// Load User Data
template<typename T>
void CurrentSessionInfo::LoadUserData(string fileName)
{
	fstream inStream;
	inStream.open(fileName, ios::binary | ios::in);
	T temp;

	if (inStream.is_open()) {
		while (inStream.read(reinterpret_cast<char*>(&temp), sizeof(T)))
		{
			userList.emplace_back(new T(temp));
		}
	}

	else cout << "Error: Could not load user data, make sure filepath is correct";
	inStream.close();
}

template<typename T>
void CurrentSessionInfo::SaveData(string fileName, vector<T>& list)
{
	fstream outStream;
	outStream.open(fileName, ios::binary | ios::out);
	if (outStream.is_open()) {
		for (T data: list)
		{
			outStream.write(reinterpret_cast<char*>(&data), sizeof(T));
		}
	}
	else cout << "Error: Could not load data, make sure filepath is correct";

	outStream.close();
}


void CurrentSessionInfo::SaveData()
{
	fstream bookOut,newspaperOut,periodicalOut,journalOut, userOut;
	bookOut.open(BOOK_FILE_PATH, ios::binary | ios::in);
	newspaperOut.open(NEWS_FILE_PATH, ios::binary | ios::in);
	periodicalOut.open(PERIODICAL_FILE_PATH, ios::binary | ios::in);
	journalOut.open(JOURNAL_FILE_PATH, ios::binary | ios::in);
	userOut.open(USER_FILE_PATH, ios::binary | ios::in);

	Book* b3 = new Book(7, "MockingJay", 15, "Fiction", "Dystopia", 5, "Amber", "89239123", 3);
	mediaList.emplace_back(b3);
	if (bookOut.is_open() && periodicalOut.is_open() && journalOut.is_open() && newspaperOut.is_open() && userOut.is_open()) {
		
		Book* writeOutBook{};
		for (int i = 0; i < mediaList.size(); i++)
		{
			
			LibraryMedia::mediaTypes currType = mediaList.at(i)->GetMediaType();
			if (currType == LibraryMedia::book) {
				writeOutBook = dynamic_cast<Book*>(mediaList.at(i));
				Book temp(*writeOutBook);
				bookOut.exceptions(std::ios::failbit);
				bookOut.write(reinterpret_cast<char*>(&temp), sizeof(Book));
			}
			else if (currType == LibraryMedia::newspaper) {

			}
			else if (currType == LibraryMedia::conferenceJournal) {

			}
			else if (currType == LibraryMedia::periodical) {

			}
		}
		delete writeOutBook;
		for (int i = 0; i < userList.size(); i++) 
		{
			userOut.write(reinterpret_cast<char*>(&userList.at(i)), sizeof(User));
		}

	}

	else cout << "Error: Could not load data, make sure filepath is correct";


	bookOut.close();
	newspaperOut.close();
	periodicalOut.close();
	journalOut.close();
	userOut.close();
}
