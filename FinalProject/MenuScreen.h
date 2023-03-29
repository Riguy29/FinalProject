#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <iostream>
#include <string>
using namespace std;

class Menu 
{
protected:
    virtual bool isValid()const = 0;
public:
    virtual void print()const = 0;
};


#endif // !MENUSCREEN_H
