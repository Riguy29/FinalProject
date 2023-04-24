#include "GuestLogin.h"

Guest::Guest(){}
Guest::~Guest(){}


void Guest::buy() {
	

}

void Guest::receipt()const {
	string name;
	cout << "Enter your name: " << endl;
	getline(cin, name);
	system("cls");

	date.printDate();

	fstream purchase;
	cout << setfill(' ') << left << setw(25) << name << endl;
	cout << setfill(' ') << setw(30) << "Thank you for you Purchase!" << endl;

	cout << setfill(' ') << setw(35) << left << "Item" << "Price" << endl;
	//for (int i = 0; i < purchaseList.size(); i++ ) {}
	cout << endl;
	purchase.open("PurchaseList.txt", ios::in | ios::out);
	if (!purchase.is_open()) {
		cout << "PurchaseList not opened successfully." << endl;
	}
	double price;
	double sum = 0.0;
	while (purchase >> price) {
		sum += price;
	}
	double taxRate = 0.05;
	double tax = sum * 0.05;

	double total = sum + tax;
	cout << setfill('-') << setw(40) << "" << endl;
	cout << setfill(' ') << fixed << setprecision(2) << setw(10) << left << "Subtotal: ";
	cout << setw(30) << right << sum << endl;
	cout << setfill(' ') << fixed << setprecision(2) << setw(10) << left << "Taxes: ";
	cout << setw(30) << right << tax << endl;
	cout << setfill(' ') << fixed << setprecision(2) << setw(10) << left << "Total: ";
	cout << setw(30) << right << total << endl;

}
