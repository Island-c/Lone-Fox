//#include "my_head.h"
#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

shared_ptr<vector<int>> new_vector()
{
	return  make_shared<vector<int>> () ;  //不要忘了后面的 ()
}

void build(shared_ptr <vector<int>> vec, istream &in)
{
	int i;
	while (in >> i)
	{
		vec->push_back(i);
	}
}

void print(shared_ptr<vector<int>> vec)
{
	for (const auto &out : *vec)
	{
		cout << out << endl;
	}
}

int main(int argc, char ** argv)
{
	shared_ptr<vector<int>> vec = new_vector();
	if (!vec)
	{
		cerr << "内存不足";
		return -1;
	}
	build(vec,cin);
	print(vec);


	system("pause");
	return 0;
}
