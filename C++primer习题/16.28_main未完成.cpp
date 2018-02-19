#include "_Shared.h"
#include "_unique.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<string>
using namespace std;


int main(int argc, char** argv)
{
	Shared<int> i(new int(100));
	cout << *i << endl;

	system("pause");
	return 0;

}
