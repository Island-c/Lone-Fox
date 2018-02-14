#include "my_head.h"
#include<iostream>
using namespace std;

int main(int argc, char*argv[])
{
	Screen<5, 3> lenovo;
	lenovo.display(cout);
	lenovo.move(4, 0).set('#');
	lenovo.display(cout);
	lenovo.move(0, 0);
	cin >> lenovo;
	cout << lenovo;

	system("pause");
	return 0;
}