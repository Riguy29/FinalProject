#pragma once
using namespace std;
#include <string>
#include "CurrentSessionInfo.h"
/* This class is used for when users want to access and change information about their account
And if admins want to find other users and change their information*/
class UserInfoAccessScreen 
{
public:
	static void printMainMenu();
	static void printUserDataMenu();
	static void SearchForUsers();

	static void CheckoutMediaInteractionMenu();
};

