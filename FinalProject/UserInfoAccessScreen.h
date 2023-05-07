#pragma once

#include "CurrentSessionInfo.h"
#include "InventoryScreen.h"
#include <string>

using namespace std;

/* This class is used for when users want to access and change information about their account
And if admins want to find other users and change their information*/

class UserInfoAccessScreen 
{
public:
	static void printMainMenu();
	static void printUserDataMenu();
	static void SearchForUsers();
	static void printAdminMenu();
};

