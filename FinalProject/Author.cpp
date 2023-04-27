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
			cout << "Enter the name of the author" << endl;
			cin >> tempName;
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
			
			isValid = false;
		}
	} while (!isValid);
}

Author::Author()
{
	bookId = -1;
	name = new string("");
}

Author::Author(int id, const string& name)
{
	bookId = id;
	this->name = new string(name);
}

Author::Author(int id)
{
	bookId = id;
	name = new string("");
}
