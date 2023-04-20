#include "PatronLogin.h"
using namespace std;

PatronLogin::PatronLogin() {}
PatronLogin::~PatronLogin(){}


void PatronLogin::borrow(){

}
void PatronLogin::placeHold(){}
void PatronLogin::renew(){}
double PatronLogin::lateFee(){
	double rate1 = 0.15;
	double rate2 = 0.25;
	double numItems = 0.0;
	double subtotal = 0;
	//double subtotalAfter = numItems * rate2;
	/*
	if (checkoutTime <= timeFunction() + 7) {
		cout<< "Thank you for returning your books. \nHave a great day!"<<endl
	}
	else if (checkoutTime > timeFunction() + 7 && checkoutTime <= timeFunction() + 14){
		subtotal = numItems * rate1;
	}
	else if ({

	}
	*/
	return subtotal;
}
void PatronLogin::printMenu()const {
	cout << "Entering the PatronLogin" << endl;
}
