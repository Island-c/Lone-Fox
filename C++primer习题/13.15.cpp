#include "my_head.h"
#include <iostream>
using namespace std;


void f(test s)
{
	s.print();
}

int main(int argc, char **argv)
{
	test new_test, new_test_2 = new_test, new_test_3 = new_test_2;
	new_test_2.print();
	f(new_test);
	f(new_test_2);
	f(new_test_3);
	system("pause");
	return 0;

}