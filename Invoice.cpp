#include "Invoice.h"


void Invoice::PrintReceipt()const {
	cout << setfill(' ') << left << setw(25) << name << endl;
	cout << setfill(' ') << setw(30) << "Thank you for you Purchase!" << endl;

	cout << setfill(' ') << setw(35) << left << "Item" << "Price" << endl;
}