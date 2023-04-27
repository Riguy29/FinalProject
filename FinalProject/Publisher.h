#pragma once
#include <string>
#include <iostream>
using namespace std;
class Publisher
{
private:
	int bookId;
	string* address;
	string* email;
	string* name;
public:
	int GetBookId();
	string& GetName();
	string& GetEmail();
	string& GetAddress();

	void SetName();
	void SetEmail();
	void SetAddress();
	void SetBookId(int bookId);

	Publisher();
	Publisher(int id, const string& newName, const string& newAddress, const string& newEmail);
	Publisher(int id); //Used when creating a new publisher as id is auto set

	void PrintInfo();
};

