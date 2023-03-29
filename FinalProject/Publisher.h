#pragma once
#include <string>
using namespace std;
class Publisher
{
private:
	string address;
	string email;
	string name;
public:
	string GetName();
	string GetEmail();
	string GetAddress();
	void SetName(string newName);
	void SetEmail(string newEmail);
	void SetAddress(string newAddress);

};

