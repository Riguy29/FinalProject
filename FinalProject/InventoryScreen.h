#pragma once
#include <iostream>
#include <string>
#include "MenuScreen.h"
#include "CheckedoutMedia.h"
class InventoryScreen : public MenuScreen
{
public:
	void SearchForBook();
	void CheckoutBook();
	void printMenu();
};

