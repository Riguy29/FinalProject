#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <iostream>
#include <string>
#include "MenuScreen.h"

class MainLogin;

class AdminMenu //: public MenuScreen 
{
private:
	
public:
	AdminMenu();
	~AdminMenu();
	void addMedia()const;
	void updateMedia()const;
	void removeMedia()const;
	void viewMedia()const;
	void search()const;
	void viewAccount()const;
	void printMenu()const;

};

#endif // !ADMINMENU_H
