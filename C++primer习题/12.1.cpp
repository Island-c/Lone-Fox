#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>

using namespace std;

int main(int argc, char ** argv)
{
	auto p1 = make_shared<vector<int>>(2,3);
	//auto p1 = make_share<vector<int>>({3,3,3});  ///make_shared不能使用列表初始化。！

	{
		auto p2 = p1;
		p2->push_back(6);
		for (auto &out : (*p1))
		{
			cout << out << "  ";
		}
		cout << endl;
		for (auto &out : (*p2))
		{
			cout << out << "  ";
		}
		cout << endl;

	}
	for (auto &out : (*p1))
	{
		cout << out << "  " ;
	}
	cout << endl;


	system("pause");
	return 0;

}