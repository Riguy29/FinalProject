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
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool valid= true;
	do
	{
		valid = true;
		string tempName;
		try
		{
			cout << "Enter the name of the publisher: " ;
			getline(cin, tempName);
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
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool valid = true;
	do
	{
		valid = true;
		string tempEmail;
		try
		{
			cout << "Enter the email of the publisher: ";
			getline(cin, tempEmail);
			//FIXME: Validate Data
			strncpy_s(email, tempEmail.c_str(), sizeof(email));
		}
		catch (int errorCode)
		{
			system("cls");
			if (errorCode == 1) {
				cout << "Publisher Name is too Long" << endl;
			}
			//Print error codes here
			valid = false;

		}
	} while (!valid);
}

void Publisher::SetAddress()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool valid = true;
	do
	{
		valid = true;
		string tempAddress;
		try
		{
			cout << "Enter the address of the publisher: " ;
			getline(cin, tempAddress, '\n');
			//Validate Data
			if (tempAddress.length() > 50) throw(1);
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
	strncpy_s(address, newAddress.c_str() , sizeof(address));
	strncpy_s(email, newEmail.c_str(), sizeof(email));
}

Publisher::Publisher(int id)
{
	bookId = id;
	strncpy_s(name, "Not set", sizeof(name));
	strncpy_s(email, "Not set", sizeof(email));
	strncpy_s(address, "Not set", sizeof(address));
}

void Publisher::PrintInfo()
{
	cout << "Publisher Info--Name: " << GetName() << " Address: " << GetAddress() << " Email: " << GetEmail();
}
