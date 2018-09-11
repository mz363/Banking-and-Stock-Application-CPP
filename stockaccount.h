#ifndef stockaccount_hpp
#define stockaccount_hpp

#include "account.h"
#include "bankaccount.h"

class stockAccount : public Account {

public:
	stockAccount();
	double symPrice(string a, string b);
	string timeNow(int a);
	string symCom(string a, string b);
	int stringToINT(string a);
	void displayCurrent(string);
	void buyStock(vector <structAccount> &stk, string, int, double);
	void sellStock(vector <structAccount> &stk, string, int, double);
	void displayPorfolio(const vector <structAccount> &stk);
	void displayTransaction();
	void menuStock();
	void sortBank(vector<structAccount> &stk);

};


#endif 