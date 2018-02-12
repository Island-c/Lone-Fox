#include "my_head.h"

#include <iostream>
#include <vector>
#include <memory>
using namespace std;


void runQueries(ifstream &infile)
{
	TextQuery tq(infile); //初始化
	TextQuery my(tq);
	TextQuery my_2;
	my_2 = my;
	my_2 = std::move(my); //测试拷贝控制成员
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, my_2.query(s)); //不是类成员。
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