#include "User.h"

User::User() {
	isAdmin = false;
	isGuest = true;

	statusLevel = "";
	firstName = "";
	lastName = "";
	username = "";
	password = "";

	userID = 0;
}