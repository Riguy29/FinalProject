#include "Publisher.h"

int Publisher::GetBookId()
{
	return bookId;
}

string Publisher::GetName()
{
	return name;
}

string Publisher::GetEmail()
{
	return email;
}

string Publisher::GetAddress()
{
	return address;
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
			strncpy_s(name, tempName.c_str(), sizeof(name));
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
			strncpy_s(email, tempEmail.c_str(), sizeof(email));
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
			strncpy_s(address, tempAddress.c_str(), sizeof(address));
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
	strncpy_s(name, "Not set", sizeof(name));
	strncpy_s(email, "Not set", sizeof(email));
	strncpy_s(address, "Not set", sizeof(address));
}

Publisher::Publisher(int id, const string& newName, const string& newAddress, const string& newEmail)
{
	bookId = id;
	strncpy_s(name, newName.c_str(), sizeof(name));
	strncpy_s(email, newAddress.c_str() , sizeof(email));
	strncpy_s(address, newEmail.c_str(), sizeof(address));
}

Publisher::Publisher(int id)
{
	bookId = id;
	strncpy_s(name, "Not set", sizeof(name));
	strncpy_s(email, "Not set", sizeof(email));
	strncpy_s(address, "Not set", sizeof(address));
}

//Publisher::Publisher(int id) {
	//bookId = id;
//}

void Publisher::PrintInfo()
{
	cout << "Publisher Info--Name: " << GetName() << " Address: " << GetAddress() << " Email: " << GetEmail();
}
