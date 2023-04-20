#include "Author.h"

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
