#include "my_head.h"
#include "Quote.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;



double print_total(ostream &os,  std::shared_ptr<Quote> item, size_t n)
{
	double ret = item->net_price(n); //总收入
	//os << "ISBN:" << item.isbn() << " #sold:" << n << " total due:" << ret << endl;
	return ret;

}
double print_total(ostream &os,Quote & item, size_t n) 
{
	double ret = item.net_price(n); //总收入
									 //os << "ISBN:" << item.isbn() << " #sold:" << n << " total due:" << ret << endl;
	return ret;

}

int main(int argc, char **argv)
{
	Quote one_book("cpp primer", 30);
	Bulk_quote two_book("cpp primer", 30, 2, 0.5);
	vector<shared_ptr<Quote>> my_vec {make_shared<Quote>(one_book) ,make_shared<Quote> (two_book)};
	double sum = 0.0;

	//对照组
	sum = print_total(cout, one_book, 2) + print_total(cout, two_book, 2);
	cout << sum << endl;
	
	//实验组
	sum = 0.0;
	for (auto &out : my_vec)
	{
		sum += print_total(cout, out, 2);
	}

	cout << sum << endl;
	system("pause");
	return 0;

}