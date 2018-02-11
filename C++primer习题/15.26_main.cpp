#include "my_head.h"
#include "Quote.h"
#include <iostream>
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n); //×ÜÊÕÈë
	os << "ISBN:" << item.isbn() << " #sold:" << n << " total due:" << ret << endl;
	return ret;

}

int main(int argc, char **argv)
{
	Quote one_book("cpp primer", 30);
	Bulk_quote two_book("cpp primer", 30, 2, 0.5);
	print_total(cout, one_book, 10);
	print_total(cout, two_book, 10);

	system("pause");
	return 0;

	system("pause");
	return 0;

}