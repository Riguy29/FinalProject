#include "CurrentSessionInfo.h"


//I guess because this is a static variable we have to define it outside of our .h file, idk thats what the internet told me and now it works so
bool CurrentSessionInfo::isUserAdmin = false;

void CurrentSessionInfo::SetAdmin(bool isAdmin)
{
	isUserAdmin = isAdmin;
}

bool CurrentSessionInfo::CheckIfAdmin()
{
	return isUserAdmin;
}
