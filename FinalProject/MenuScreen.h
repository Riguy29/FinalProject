#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <iostream>
#include <string>
using namespace std;

class MenuScreen 
{
protected:
    
public:
    virtual void printMenu()const = 0;
	virtual void search()const;
	virtual void viewAccount()const;
	virtual void exit()const;
};


#endif // !MENUSCREEN_H
