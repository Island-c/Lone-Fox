#include "my_head.h"

#include<iostream>

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile); //初始化
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)); //不是类成员。
	}

}


int main(int argc, char** argv)
{
	ifstream in(argv[1]);
	if (!in)
	{
		throw runtime_error("error open");
	}
	runQueries(in);


	system("pause");
	return 0;
}