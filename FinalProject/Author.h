#pragma once
#include <string>
#include <iostream>
using namespace std;
class Author
{
private:
	int bookId;
	char name[100];
public:
	int GetBookId();
	string GetName();
	void SetName();
	Author();
	Author(int id, const string& name);
	Author(int id); //Constructer to be used during runtime when adding media as bookId will be set automattiacly
};