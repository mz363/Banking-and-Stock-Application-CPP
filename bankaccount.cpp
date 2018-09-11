#include "bankaccount.h"

bankAccount::bankAccount()
{

}

string bankAccount::timeNow(int a)
{
#pragma warning(disable: 4996)
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string th = to_string(ltm->tm_hour);
	string tm = to_string(ltm->tm_min);
	string ts = to_string(ltm->tm_sec);
	string ty = to_string(1900 + ltm->tm_year);
	string tmn = to_string(1 + ltm->tm_mon);
	string td = to_string(ltm->tm_mday);
	string colon = ":";
	string slash = "/";
	string times;
	if (a == 1)
		times = th + colon + tm + colon + ts;
	else if (a == 2)
		times = tmn + slash + td + slash + ty;
	return times;
#pragma warning(default: 4996)
}

void bankAccount::displayBalance() {
	double value = 0.0;
	string col1, col2, col3, col4, col5;
	cout << "Cash balance = $" << cashBalance() << endl << endl;
	cout << setw(8) << left << "Symbol" << setw(24) << left << "Company" << setw(8) << left << "Number" << setw(8) << left << "Price" << left << "Total" << endl;

	string STRING;
	ifstream f;
	f.open("stockvector.txt");
	while (!f.eof()) 
	{
		getline(f, STRING);
		cout << STRING << endl; 
	}
	f.close();

	f.open("stockvector.txt");
	f >> col1 >> col2 >> col3 >> col4 >> col5;
	while (!f.fail())
	{
		value = atof(col5.c_str());
		f >> col5;
	}


	cout << "Total portfolio value: $" << value + cashBalance() << endl << endl;
}

void bankAccount::depositBank(double deposit) {
	cout << "Deposit $" << deposit << " to bank account" << endl << endl;
	string line;
	double a;
	fstream f3;
	f3.open("cashbalance.txt", fstream::in);
	for (int i = 0; i<1; i++)
	{
		getline(f3, line);
	}
	a = atof(line.c_str());
	a += deposit;
	f3.close();
	f3.open("cashbalance.txt", fstream::out | fstream::trunc);
	f3 << a;
	f3.close();

	ofstream f;
	f.open("bank_transaction_history.txt", ios::out | ios::app);
	f << setw(10) << left << "Deposit" << setw(10) << left << deposit << setw(16) << left << cashBalance() << setw(14) << left << timeNow(2) << left << timeNow(1) << endl;
	f.close();

	displayBalance();

}

void bankAccount::withdrawBank(double withdraw) {
	cout << "Withdraw $" << withdraw << " to bank account" << endl << endl;
	string line;
	double a;
	fstream f3;
	f3.open("cashbalance.txt", fstream::in);
	for (int i = 0; i<1; i++)
	{
		getline(f3, line);
	}
	a = atof(line.c_str());
	a -= withdraw;
	f3.close();
	f3.open("cashbalance.txt", fstream::out | fstream::trunc);
	f3 << a;
	f3.close();

	ofstream f;
	f.open("bank_transaction_history.txt", ios::out | ios::app);
	f << setw(10) << left << "Withdraw" << setw(10) << left << withdraw << setw(16) << left << cashBalance() << setw(14) << left << timeNow(2) << left << timeNow(1) << endl;
	f.close();

	displayBalance();

}

void bankAccount::displayHistory() {
	string STRING;
	cout << setw(10) << left << "Action" << setw(10) << left << "Amount" << setw(16) << left << "Cash Balance" << setw(14) << left << "Date" << left << "Time" << endl;
	ifstream f;
	f.open("bank_transaction_history.txt");
	while (!f.eof()) 
	{
		getline(f, STRING);
		cout << STRING << endl; 
	}
	f.close();

}

void bankAccount::menuBank()
{
	bool flag = true;
	int selection;
	char test[256];
	while (flag) {
		cout << "Please select an option" << endl;
		cout << "\t1. View account balance\n\t2. Deposit money\n\t3. Withdraw money\n\t4. Display transactions history\n\t5. Return to previous menu" << endl;
		cout << "Your Selection:\t";


		cin.getline(test, 256);
		cout << test << endl;
		cout << endl;
		selection = atoi(test);

		switch (selection) {
		case 1:
			displayBalance();
			break;
		case 2: {
			char line[256];
			double amount;
			cout << "Deposit amount: ";
			cin.getline(line, 256);
			cout << line << endl << endl;
			amount = stod(line);
			depositBank(amount);
			break;
		}
		case 3: {
			char line[256];
			double amount;
			cout << "Withdraw amount: ";
			cin.getline(line, 256);
			cout << line << endl << endl;
			amount = stod(line);
			withdrawBank(amount);
			break;
		}
		case 4:
			displayHistory();
			break;
		case 5:
			flag = false;
			break;
		default:
			break;
		}
	}
}