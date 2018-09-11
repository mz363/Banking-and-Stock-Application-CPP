#include "stockaccount.h"

stockAccount::stockAccount()
{

}

int stockAccount::stringToINT(string a)
{
	string Stocks[36] = { "","VNET","AGTK","AKAM","BIDU","BCOR","WIFI","CARB","JRJC","CCIH","CCOI","CXDO","EDXC","ENV","FB","GDDY","IAC","IIJI","INAP","IPAS","JCOM","LLNW","MOMO","NTES","EGOV","NQ","OPESY","BLNKF","NAME","SIFY","SINA","SOHU","SNST","TCTZF","TCEHY","TMMI" };
	string numStocks[36] = { "","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35" };

	for (int i = 0; i < 36; i++)
	{
		if (a == Stocks[i])
			a = numStocks[i];
		//        if (a != Stocks[i]){
		//            cout << "The stock is not avaliable" << endl;
		//            break;
		//        }
	}

	int b = atoi(a.c_str());
	return b;
}

string stockAccount::symCom(string stockSym, string symStock) {
	string col1, col2, col3, col4, col5, col6;
	string companys;
	string space = " ";

	istringstream ss(symStock);
	ss >> col1 >> col2 >> col3 >> col4 >> col5 >> col6;

	if (stockSym == "VNET" || stockSym == "JRJC" || stockSym == "FB" || stockSym == "GDDY" || stockSym == "IIJI" || stockSym == "NQ" || stockSym == "OPESY" || stockSym == "SIFY" || stockSym == "SNST" || stockSym == "TCEHY")
		companys = col2 + space + col3 + space + col4 + space + col5;
	else if (stockSym == "AGTK" || stockSym == "AKAM" || stockSym == "BIDU" || stockSym == "WIFI" || stockSym == "CCIH" || stockSym == "CCOI" || stockSym == "JCOM" || stockSym == "LLNW" || stockSym == "MOMO" || stockSym == "NTES" || stockSym == "NAME" || stockSym == "TCTZF")
		companys = col2 + space + col3 + space + col4;
	else if (stockSym == "BCOR" || stockSym == "CARB" || stockSym == "CXDO" || stockSym == "EDXC" || stockSym == "ENV" || stockSym == "INAP" || stockSym == "IPAS" || stockSym == "EGOV" || stockSym == "BLNKF" || stockSym == "SINA" || stockSym == "SOHU" || stockSym == "TMMI")
		companys = col2 + space + col3;
	else if (stockSym == "IAC")
		companys = col2;

	return companys;
}

double stockAccount::symPrice(string stockSym, string symStock) {
	string col1, col2, col3, col4, col5, col6;
	double price1 = 0.0;

	istringstream ss(symStock);
	ss >> col1 >> col2 >> col3 >> col4 >> col5 >> col6;

	if (stockSym == "VNET" || stockSym == "JRJC" || stockSym == "FB" || stockSym == "GDDY" || stockSym == "IIJI" || stockSym == "NQ" || stockSym == "OPESY" || stockSym == "SIFY" || stockSym == "SNST" || stockSym == "TCEHY")
		price1 = atof(col6.c_str());
	else if (stockSym == "AGTK" || stockSym == "AKAM" || stockSym == "BIDU" || stockSym == "WIFI" || stockSym == "CCIH" || stockSym == "CCOI" || stockSym == "JCOM" || stockSym == "LLNW" || stockSym == "MOMO" || stockSym == "NTES" || stockSym == "NAME" || stockSym == "TCTZF")
		price1 = atof(col5.c_str());
	else if (stockSym == "BCOR" || stockSym == "CARB" || stockSym == "CXDO" || stockSym == "EDXC" || stockSym == "ENV" || stockSym == "INAP" || stockSym == "IPAS" || stockSym == "EGOV" || stockSym == "BLNKF" || stockSym == "SINA" || stockSym == "SOHU" || stockSym == "TMMI")
		price1 = atof(col4.c_str());
	else if (stockSym == "IAC")
		price1 = atof(col3.c_str());

	return price1;
}

string stockAccount::timeNow(int a)
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

void stockAccount::displayCurrent(string stockSym)
{
	srand(unsigned(time(NULL)));
	int choice = rand() % 4 + 1;
	string symStock, col1, col2, col3, col4, col5, col6, choice1 = to_string(choice);;

	ifstream f("stock1.txt");
	for (int i = 0; i<stringToINT(stockSym); i++)
	{
		getline(f, symStock);
	}
	istringstream ss(symStock);
	ss >> col1 >> col2 >> col3 >> col4 >> col5 >> col6;
	cout << endl;

	cout << setw(8) << left << col1 << setw(26) << left << symCom(stockSym, symStock) << setw(8) << left << symPrice(stockSym, symStock) << left << timeNow(1) << endl;
	cout << endl;
}


void stockAccount::buyStock(vector <structAccount> &stk, string stockSym, int num, double priceRange)
{
	structAccount info;
	srand(unsigned(time(NULL)));
	double price = 0.0;
	int choice = rand() % 4 + 1;
	string col1, col2, col3, col4, col5, col6, choice1 = to_string(choice);
	string symStock;

	ifstream f("stock" + choice1 + ".txt");
	for (int i = 0; i<stringToINT(stockSym); i++) {
		getline(f, symStock);
	}
	istringstream ss(symStock);
	ss >> col1 >> col2 >> col3 >> col4 >> col5 >> col6;

	price = symPrice(stockSym, symStock);
	if (priceRange >= price) {

		string line;
		double a;
		fstream f3;
		f3.open("cashbalance.txt", fstream::in);
		for (int i = 0; i<1; i++)
		{
			getline(f3, line);
		}
		a = atof(line.c_str());
		a -= priceRange*num;
		f3.close();
		f3.open("cashbalance.txt", fstream::out | fstream::trunc);
		f3 << a;
		f3.close();

		ofstream f1;
		f1.open("stock_transaction_history.txt", ios::out | ios::app);
		f1 << setw(12) << left << "Buy" << setw(12) << left << col1 << setw(12) << left << num << setw(11) << left << fixed << setprecision(2) << priceRange << left << timeNow(1) << endl;
		f.close();

		info.symbol = col1;
		info.company = symCom(stockSym, symStock);
		info.number = num;
		info.price = price;
		info.total = price*num;
		info.sorting = stringToINT(stockSym);

		for (int i = 0; i<stk.size(); ++i) {
			if (stockSym != stk[i].symbol) {
				stk.push_back(info);
				break;
			}
			else if (stockSym == stk[i].symbol)
				stk[i].symbol = col1;
			stk[i].price = price;
			stk[i].number += num;
			stk[i].total += price*num;
			stk[i].company = symCom(stockSym, symStock);
			break;
		}
		if (stk.size() == 0)
			stk.push_back(info);

	}
	else if (priceRange < price) {
		cout << "Cannot process transaction. " << endl;
	}
}

void stockAccount::displayPorfolio(const vector <structAccount> &stk) {
	double value = 0.0;
	cout << endl;
	cout << "Cash balance = $" << cashBalance() << endl << endl;
	cout << setw(8) << left << "Symbol" << setw(24) << left << "Company" << setw(8) << left << "Number" << setw(8) << left << "Price" << left << "Total" << endl;
	ofstream f1;
	f1.open("stockvector.txt", fstream::out | fstream::trunc);
	for (int i = 0; i < stk.size(); ++i) {
		f1 << setw(8) << left << stk[i].symbol << setw(24) << left << stk[i].company << setw(8) << left << stk[i].number << setw(8) << left << fixed << setprecision(2) << stk[i].price << left << setprecision(2) << stk[i].total << endl;
		value += stk[i].total;
	}
	f1.close();

	string STRING;
	ifstream f;
	f.open("stockvector.txt");
	while (!f.eof()) 
	{
		getline(f, STRING); 
		cout << STRING << endl; 
	}
	f.close();

	cout << "Total portfolio value: $" << fixed << setprecision(2) << value + cashBalance() << endl << endl;
}

void stockAccount::displayTransaction() {
	string STRING;
	cout << setw(12) << left << "Action" << setw(12) << left << "Symbol" << setw(12) << left << "Shares" << setw(11) << left << "Price" << left << "Time" << endl;
	ifstream f;
	f.open("stock_transaction_history.txt");
	while (!f.eof()) 
	{
		getline(f, STRING); 
		cout << STRING << endl;
	}
	f.close();
}

void stockAccount::menuStock()
{
	vector <structAccount> stk;
	bool flag = true;
	int selection;
	char test[256];
	while (flag) {

		cout << "Please select an option" << endl;
		cout << "\t1. Display current price for a stock symbol\n\t2. Buy stock\n\t3. Sell stock\n\t4. Display current portfolio\n\t5. Display transactions history\n\t6. Return to main menu" << endl;
		cout << "Your Selection:\t";

		cin.getline(test, 256);
		cout << test << endl;
		selection = atoi(test);


		switch (selection) {
		case 1: {
			char line[256];
			cout << endl;
			cout << "Enter stock symbol for checking price: ";
			cin.getline(line, 256);
			cout << line;
			cout << endl;
			string symbol(line);
			displayCurrent(symbol);
			break;
		}
		case 2: {
			string a, b, c;
			char line[256];

			cout << endl;
			cout << "Enter buy options: ";

			cin.getline(line, 256);
			cout << line << endl;
			cout << endl;
			istringstream ss(line);
			ss >> a >> b >> c;

			string symbol = a;
			int numShare = atoi(b.c_str());
			double price = atof(c.c_str());

			buyStock(stk, symbol, numShare, price);
			break;
		}
		case 3: {
			string a, b, c;
			char line[256];

			cout << endl;
			cout << "Enter selling options: ";

			cin.getline(line, 256);
			cout << line << endl;
			cout << endl;
			istringstream ss(line);
			ss >> a >> b >> c;

			string symbol = a;
			int numShare = atoi(b.c_str());
			double price = atof(c.c_str());

			sellStock(stk, symbol, numShare, price);
			break;
		}
		case 4:
			displayPorfolio(stk);
			break;
		case 5:
			cout << endl;
			displayTransaction();
			break;
		case 6:
			cout << endl;
			flag = false;
			break;
		default:
			break;
		}
	}
}
void stockAccount::sellStock(vector <structAccount> &stk, string stockSym, int num, double priceRange) {
	structAccount info;
	srand(unsigned(time(NULL)));
	double price = 0.0;
	int choice = rand() % 4 + 1;
	string col1, col2, col3, col4, col5, col6, choice1 = to_string(choice);
	string symStock;

	ifstream f("stock" + choice1 + ".txt");
	for (int i = 0; i<stringToINT(stockSym); i++) {
		getline(f, symStock);
	}
	istringstream ss(symStock);
	ss >> col1 >> col2 >> col3 >> col4 >> col5 >> col6;

	price = symPrice(stockSym, symStock);
	if (priceRange <= price) {

		string line;
		double a;
		fstream f3;
		f3.open("cashbalance.txt", fstream::in);
		for (int i = 0; i<1; i++)
		{
			getline(f3, line);
		}
		a = atof(line.c_str());
		a += priceRange*num;
		f3.close();
		f3.open("cashbalance.txt", fstream::out | fstream::trunc);
		f3 << a;
		f3.close();

		ofstream f1;
		f1.open("stock_transaction_history.txt", ios::out | ios::app);
		f1 << setw(12) << left << "Sell" << setw(12) << left << col1 << setw(12) << left << num << setw(11) << left << priceRange << left << timeNow(1) << endl;
		f.close();

		info.symbol = col1;
		info.company = symCom(stockSym, symStock);
		info.number = num;
		info.price = price;
		info.total = price*num;

		for (int i = 0; i<stk.size(); ++i) {
			if (stockSym != stk[i].symbol) {
				cout << "you do not have this stock" << endl;
				break;
			}
			else if (stockSym == stk[i].symbol)
				stk[i].symbol = col1;
			stk[i].price = price;
			stk[i].number -= num;
			stk[i].total = price*stk[i].number;
			stk[i].company = symCom(stockSym, symStock);
			break;
		}
		if (stk.size() == 0)
			cout << "You do not have this stock." << endl;

	}
	else if (priceRange > price)
		cout << "Cannot process transaction. " << endl;
}

void stockAccount::sortBank(vector<structAccount> &stk) {
	int finish = 0;
	while (finish == 0) {
		for (int i = 0; i < stk.size() - 1; i++) {
			if (stk[i].sorting > stk[i + 1].sorting) {
				swap(stk[i].symbol, stk[i + 1].symbol);
				swap(stk[i].company, stk[i + 1].company);
				swap(stk[i].number, stk[i + 1].number);
				swap(stk[i].price, stk[i + 1].price);
				swap(stk[i].total, stk[i + 1].total);
				swap(stk[i].sorting, stk[i + 1].sorting);
				continue;
			}
		}
		finish = 1;
	}
}