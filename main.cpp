#include <iostream>
#include <fstream>
#include "account.h"
#include "stockaccount.h"
#include "bankaccount.h"
#include <algorithm>

int main(int argc, const char * argv[]) {
	stockAccount account1;
	bankAccount account2;

	bool flag = true;
	int selection = 0;
	char test[256];
	string line;
	while (flag) {

		cout << "Welcome to the Account Manement System." << endl;
		cout << "Please select an account to access" << endl;
		cout << "\t1. Stock Portfolio Account\n\t2. Bank Account\n\t3. Exit" << endl;
		cout << "Your Selection:\t";

		cin.getline(test, 256);
		cout << test << endl;
		cout << endl;
		selection = atoi(test);

		switch (selection) {
		case 1:
			account1.menuStock();
			break;
		case 2:
			account2.menuBank();
			break;
		case 3:
			cout << "Program Terminated.";
			exit(1);
		default:
			break;
		}
	}
	return 0;
}
