#include "account.h"

Account::Account()
{

}

Account::~Account()
{

}

double Account::cashBalance() {
	string line;
	double a;
	ifstream f("cashbalance.txt");
	for (int i = 0; i<1; i++)
	{
		getline(f, line);
	}
	a = atof(line.c_str());
	return a;
}