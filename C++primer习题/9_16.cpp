#include<iostream>
#include<list>
#include<vector>

using namespace std;

bool compare(list<int> a, vector<int> b)
{
	if (a.size() != b.size())
		return false;
	/*for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])	return false;
	}*/
	auto ll = a.begin();
	auto llend = a.end();
	auto vv = b.begin();
	for (; ll != llend; ++ll, ++vv)
	{
		if (*ll != *vv) return false;
	}
	return true;

}

int main(int argc, char** argv)
{
	list<int> ilist_1 = { 1,2,3,4,5 };
	list<int> ilist_2 = { 1,2,3,4,5,6 };
	vector<int> ivec = { 1,2,3,4,5 };

	cout << compare(ilist_1, ivec) << " " << compare(ilist_2, ivec) << endl;

	system("pause");
	return 0;
}