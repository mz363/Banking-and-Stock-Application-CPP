#ifndef bankaccount_hpp
#define bankaccount_hpp

#include "account.h"
#include "stockaccount.h"

class bankAccount : public Account {

public:
	bankAccount();
	void menuBank();
	string timeNow(int);
	void displayBalance();
	void depositBank(double);
	void withdrawBank(double);
	void displayHistory();

};

#endif 