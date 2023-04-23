#include "CurrentSessionInfo.h"

//I guess because this is a static variable we have to define it outside of our .h file, idk thats what the internet told me and now it works so
bool CurrentSessionInfo::isUserAdmin = false;
vector<Publisher> CurrentSessionInfo::pubList;
vector<Author> CurrentSessionInfo::authorList;
vector<Book> CurrentSessionInfo::bookList;
vector< unique_ptr<LibraryMedia>> CurrentSessionInfo::mediaList;

void CurrentSessionInfo::SetAdmin(bool isAdmin) { isUserAdmin = isAdmin; }

bool CurrentSessionInfo::CheckIfAdmin()
{
	return isUserAdmin;
}
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
//vector<LibraryMedia*> CurrentSessionInfo::GetLibraryInventory()
//{
//	return mediaList;
//}
void CurrentSessionInfo::LoadInventory(bool generateDummyData)
{
	LoadData<Book>("BookRecord.txt", bookList);
	LoadData<Publisher>("PublisherRecord.txt", pubList);
	LoadData<Author>("AuthorRecord.txt", authorList);


	LoadData<Book>("BookRecord.txt");
	LoadData<Newspaper>("NewspaperRecord.txt");
	LoadData<Periodical>("PeriodicalRecord.txt");
	//LoadData<ConferenceJournal>("JournalRecord.txt");

	
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


template<typename T>
void CurrentSessionInfo::LoadData(string fileName)
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
	else cout << "Error: Could not load data, make sure filepath is correct";

	inStream.close();
}

template<typename T>
void CurrentSessionInfo::SaveData(string fileName, vector<T>& list)
{
}
