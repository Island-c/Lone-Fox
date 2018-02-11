#include "my_head.h"

#include <iostream>
#include <vector>
#include <memory>
using namespace std;



int main(int argc, char **argv)
{
	Quote one_book("cpp primer", 30);
	Bulk_quote two_book("cpp primer", 30, 2, 0.5);
	vector<shared_ptr<Quote>> my_vec {make_shared<Quote>(one_book) ,make_shared<Quote> (two_book)};
	double sum = 0.0;
	//∂‘’’
	for (auto &out : my_vec)
	{
		sum += print_total(cout, out, 1);
	}

	cout << sum << endl;
	
	// µ—È
	Basket my_bag;
	my_bag.add_item(one_book);
	my_bag.add_item(two_book);
	my_bag.total_receipt(cout);
	system("pause");
	return 0;

}