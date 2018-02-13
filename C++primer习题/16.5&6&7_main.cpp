#include "my_head.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<string>
using namespace std;

int main(int argc, char** argv)
{

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9,10};
	print(a);
	auto beg = my_begin(a);
	auto end = my_end(a);
	cout << *beg << "  " << *end << endl;
	cout << my_size(a) << endl;

	system("pause");
	return 0;

}
