#pragma once
#include <string>
using namespace std;
class Author
{
public:
	int bookId;
	string* name;

	Author();
	Author(int id, const string& name);
};