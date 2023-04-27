#pragma once
#include <string>
#include <iostream>
using namespace std;
class Publisher
{
private:
	int bookId;
	char address[50];
	char email[50];
	char name[50];
public:
	int GetBookId();
	string GetName();
	string GetEmail();
	string GetAddress();

	void SetName();
	void SetEmail();
	void SetAddress();
	void SetBookId(int bookId);

	Publisher();
	Publisher(int id, const string& newName, const string& newAddress, const string& newEmail);
	Publisher(int id); //Used when creating a new publisher as id is auto set

	void PrintInfo();
};

