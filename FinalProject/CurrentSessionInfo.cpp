#include "CurrentSessionInfo.h"

//I guess because this is a static variable we have to define it outside of our .h file, idk thats what the internet told me and now it works so
bool CurrentSessionInfo::isUserAdmin = false;
//LinkedList<Book> CurrentSessionInfo::bookList = LinkedList<Book>();
//LinkedList<ConferenceJournal> CurrentSessionInfo::journalList = LinkedList<ConferenceJournal>();
//LinkedList<Newspaper> CurrentSessionInfo::newspaperList = LinkedList<Newspaper>();
//LinkedList<Periodical> CurrentSessionInfo::periodicalList = LinkedList<Periodical>();
//LinkedList<Publisher> CurrentSessionInfo::publisherList = LinkedList<Publisher>();
//LinkedList<Author> CurrentSessionInfo::authorList = LinkedList<Author>();
vector<Publisher> CurrentSessionInfo::pubList;
vector<Author> CurrentSessionInfo::authorList;
vector<Book> CurrentSessionInfo::bookList;

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
}
void CurrentSessionInfo::LoadInventory(bool generateDummyData)
{
	LoadData<Publisher>("PublisherRecord.txt", pubList);
	LoadData<Author>("AuthorRecord.txt", authorList);
	LoadData<Book>("BookRecord.txt", bookList);

	
}
template<typename T>
void CurrentSessionInfo::LoadData(string fileName, vector<T>& list)
{
	fstream inStream;
	inStream.open(fileName, ios::binary | ios::in);
	T temp;
	while (inStream.read(reinterpret_cast<char*>(&temp), sizeof(T)))
	{
		list.push_back(temp);
	}

	inStream.close();
}

template<typename T>
void CurrentSessionInfo::SaveData(string fileName, vector<T>& list)
{
}
