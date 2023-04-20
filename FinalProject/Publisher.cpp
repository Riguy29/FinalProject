#include "Publisher.h"

int Publisher::GetBookId()
{
	return bookId;
}

string& Publisher::GetName()
{
	return *name;
}

string& Publisher::GetEmail()
{
	return *email;
}

string& Publisher::GetAddress()
{
	return *address;
}

void Publisher::SetName(string newName)
{
	name = new string(newName);
}

void Publisher::SetEmail(string newEmail)
{
	email = new string(newEmail);
}

void Publisher::SetAddress(string newAddress)
{
	address =new string( newAddress );
}

Publisher::Publisher()
{
	bookId = -1;
	name = new string(" ");
	address = new string(" ");
	email = new string(" ");
}

Publisher::Publisher(int id, const string& newName, const string& newAddress, const string& newEmail)
{
	bookId = id;
	name = new string(newName);
	address = new string(newAddress);
	email = new string(newEmail);
}

void Publisher::PrintInfo()
{
	cout << "Publisher Info--Name: " << GetName() << " Address: " << GetAddress() << " Email: " << GetEmail();
}
