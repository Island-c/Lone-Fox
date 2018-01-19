#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<string> ivec;
	string my_str;
	while (cin >> my_str)
		ivec.insert(ivec.begin(), my_str);
	for (auto i = ivec.cbegin(); i != ivec.end(); ++i)
	{
		cout << *i << endl;
	}

	system("pause");
	return 0;
}