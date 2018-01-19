#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<string> ivec;
	string my_str;
	auto ii = ivec.begin();
	while (cin >> my_str)
		ii=ivec.insert(ii, my_str); //必须把返回值赋给迭代器，因为插入元素后 原来的迭代器会失效。
	for (auto i = ivec.cbegin(); i != ivec.end(); ++i)
	{
		cout << *i << endl;
	}

	system("pause");
	return 0;
}