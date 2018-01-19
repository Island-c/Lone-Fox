#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	vector<int> vec;
	int a;
	string str("my");
	while (cin >> a)
	{
		vec.push_back(a);
	}

	auto i = find_if(vec.begin(), vec.end(), bind(check_size, _1, str.size()));
	
	//for (auto& it : vec)	cout << it << "   ";
	//for (auto iter = vec.begin(); iter != vec.end(); ++iter)
		//cout << *iter << " ";
	//for_each(vec.begin(), vec.end(), [](const string& str) {cout << str << " "; });

	cout << endl;
	cout << *i << endl;

	system("pause");
	return 0;
}