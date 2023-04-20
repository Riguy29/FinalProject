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

	void SetName(string newName);
	void SetEmail(string newEmail);
	void SetAddress(string newAddress);
	void SetBookId(int bookId);

	Publisher();
	Publisher(int id, const string& newName, const string& newAddress, const string& newEmail);

	void PrintInfo();
};

