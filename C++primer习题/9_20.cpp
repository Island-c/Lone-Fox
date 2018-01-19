#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main(int argc, char** argv)

{
	list<int> ilist = { 1,2,3,4,5,6,7,8,9 };
	deque<int> d1;
	deque<int> d2;
	int i = 1;
	for (auto iter = ilist.cbegin(); iter != ilist.end(); ++iter,++i)
	{
		if (i % 2 == 0)	d1.push_back(*iter);
		if (i % 2 == 1) d2.push_back(*iter);
		
	}
	cout << "Å¼Êı:" << endl;
	for (auto iter = d1.cbegin(); iter != d1.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "ÆæÊı:" << endl;
	for (auto iter = d2.cbegin(); iter != d2.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}