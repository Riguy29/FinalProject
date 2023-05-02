#include "Author.h"

void Author::SetName()
{
	bool isValid = true;
	do
	{
		isValid = true;
		try
		{
			string tempName;
			cout << "Enter the name of the author: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			
			isValid = false;
		}
	} while (!isValid);
}

Author::Author()
{
	bookId = -1;
	strncpy_s(name, "Not Set", sizeof(name));
}

Author::Author(int id, const string& n)
{
	bookId = id;
	strncpy_s(name, n.c_str(), sizeof(name));
}

Author::Author(int id)
{
	bookId = id;
	strncpy_s(name, "Not Set", sizeof(name));
}
