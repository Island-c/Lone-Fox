#include<iostream>
#include<vector>

using namespace std;
int main(int argc, char **argv)
{
	vector<int> ivec = { 1,2,3 };
	vector <int> test;
	test.push_back(ivec[0]);
	test.push_back(ivec.at(0));
	test.push_back(ivec.front());
	test.push_back(*ivec.begin());

	for (auto i = test.cbegin(); i != test.end(); ++i)
	{
		cout << *i << endl;
	}


	system("pause");
	return 0;
}