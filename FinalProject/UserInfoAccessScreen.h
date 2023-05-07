#pragma once

#include "CurrentSessionInfo.h"
#include "InventoryScreen.h"
#include <string>
#include <vector>

using namespace std;

/* This class is used for when users want to access and change information about their account
And if admins want to find other users and change their information*/

class UserInfoAccessScreen 
{
private:
	static vector<reference_wrapper<CheckedoutMedia>> usersCheckedoutMedia;
public:
	static void DisplayCheckedoutMedia();
	static void printMainMenu();
	static void printUserDataMenu();
	static void SearchForUsers();
	static void printAdminMenu();
	static void CheckoutMediaInteractionMenu(CheckedoutMedia& selectedMedia, bool& mediaReturned);
};

