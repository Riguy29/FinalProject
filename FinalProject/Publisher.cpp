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

void Publisher::SetName()
{
	bool valid= true;
	do
	{
		valid = true;
		string tempName;
		try
		{
			cin >> tempName;
			cout << "Enter the name of the publisher" << endl;
			for (char nameChar : tempName) {
				if (isdigit(nameChar)) throw(1);
			}
			//If we throw no errors set name
			name = new string(tempName);
		}
		catch (int errorCode)
		{
			system("cls");
			if (errorCode == 1) {
				cout << "A name should not have digits" << endl;
			}

			valid = false;

		}
	} while (!valid);
}

void Publisher::SetEmail()
{
	bool valid = true;
	do
	{
		valid = true;
		string tempEmail;
		try
		{
			cin >> tempEmail;
			cout << "Enter the name of the publisher" << endl;
			//FIXME: Validate Data
			email = new string(tempEmail);
		}
		catch (int errorCode)
		{
			system("cls");
			//Print error codes here
			valid = false;

		}
	} while (!valid);
}

void Publisher::SetAddress()
{
	bool valid = true;
	do
	{
		valid = true;
		string tempAddress;
		try
		{
			cin >> tempAddress;
			cout << "Enter the name of the publisher" << endl;
			//Validate Data
			address = new string(tempAddress);
		}
		catch (int errorCode)
		{
			system("cls");
			if (errorCode == 1) {
				cout << "A name should not have digits" << endl;
			}

			valid = false;

		}
	} while (!valid);
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

Publisher::Publisher(int id) {
	bookId = id;
}

void Publisher::PrintInfo()
{
	cout << "Publisher Info--Name: " << GetName() << " Address: " << GetAddress() << " Email: " << GetEmail();
}
