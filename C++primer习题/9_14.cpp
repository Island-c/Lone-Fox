#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

int main(int argc, char** argv)
{
	list<char*> ilist{ "we","are","family" };
	vector<string> ivec;
	ivec.assign(ilist.begin(), ilist.end());
	cout << ivec.capacity() << " " << ivec.size() << " " << endl;
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}