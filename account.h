#ifndef account_hpp
#define account_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <algorithm>
using namespace std;

struct structAccount {
	string symbol;
	string company;
	int number;
	double price;
	double total = 0.0;
	int sorting;
};

class Account {

public:
	Account();
	~Account();
	double cashBalance();
};


#endif 