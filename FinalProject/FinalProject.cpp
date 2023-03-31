
#include "LibraryLinkedList.h"
#include "Test.h"
#include "Login.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
//#include <stdlib.h>

using namespace std;

void TimeFunction() {
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	//cout << "The local date and time is: " << dt << endl;

	// convert now to tm struct for UTC
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	//cout << "The date and time is: " << dt << endl;
	cout << dt << endl;
}

int main()
{
	TimeFunction();
	Login login;
	login.printMenu();

	


	/*
	//creating objects of BookList for testing LinkedList functions
	BookList* book1 = new BookList("Harry Potter", "J.K. Rowling", "2001", 1, 8909789098, " ", " ", 35.00);
	BookList* book2 = new BookList("Bad Guys", "Blabey", "2011", 23, 9809876678, " ", " ", 10.00);
	BookList* book3 = new BookList("Information System", "Earl H. McKinney", " Pearson", 2022, 0136567, " ", " ", 75.00);


	LinkedList<BookList*> Books;

	Books.insertItem(book1);
	Books.insertItem(book2);
	Books.insertItem(book3);
	Books.printList();
	cout << "delete book1" << endl;
	Books.deleteItem(book1);

	Books.printList();

	
	cout << endl;
	LinkedList<string> Books;
	Books.insertItem("Harry Potter");
	Books.insertItem("Information System");
	Books.insertItem("Data Structures");
	Books.insertItem("Throne of Glass");
	Books.insertItem("Man called Otto");
	Books.insertItem("");
	Books.printList();
	cout << endl;
	cout << "size of the list is: ";
	cout << Books.size() << endl;
	cout << endl;

	cout << "Delete item Harry Potter and Spiderwick" << endl;
	Books.deleteItem("Harry Potter");
	Books.deleteItem("Spiderwick");
	Books.printList();
	cout << endl;
	cout << "size of the list is: ";
	cout << Books.size() << endl;
	cout << endl;

	cout << "insert Bad Guys" << endl;
	Books.insertItem("Bad Guys");
	Books.printList();
	cout << endl;

	cout << "size of the list is: ";
	cout << Books.size() << endl;
	cout << endl;

	cout << "get value at index 4 and 2" << endl;
	cout << Books.getItem(4) << endl;
	cout << Books.getItem(2) << endl;
	*/
	return 0;
	
}