#include<iostream>
#include<vector>

using namespace std;

bool search_vec(vector<int>::iterator beg,
	vector<int>::iterator end, int val)
{
	for (; beg != end; ++beg)
	{
		if (*beg == val)
			return true;
	}
	return false;

}

int main()
{
	vector<int > llist = { 1,2,3,4,5,6,7,8,9 };
	cout << search_vec(llist.begin(), llist.end(), 3) << endl;
	system("pause");
	return 0;
}