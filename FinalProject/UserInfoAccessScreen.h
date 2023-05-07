#pragma once
using namespace std;
#include <string>
#include <vector>
#include "CurrentSessionInfo.h"
#include "CheckedoutMedia.h"
/* This class is used for when users want to access and change information about their account
And if admins want to find other users and change their information*/
class UserInfoAccessScreen 
{
private:
	static vector<CheckedoutMedia> usersCheckedoutMedia;
public:
	static void DisplayCheckedoutMedia();
	static void printMainMenu();
	static void printUserDataMenu();
	static void SearchForUsers();

	static void CheckoutMediaInteractionMenu(CheckedoutMedia& selectedMedia, bool& mediaReturned);
};

