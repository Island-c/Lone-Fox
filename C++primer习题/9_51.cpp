#include "9_51.h"
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char ** argv)
{
	string dates[] = { "Jan 1,2014", "February 1 2014","3/1/2014","3 1 2014" };
	try {
		for (auto ds : dates) {
			date dl(ds);
			cout << dl;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}


	system("pause");
	return 0;

}