#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(int argc, char** argv)
{
	list <int> ilist = { 1,2,3,4,5,6,7 };
	vector<int> ivec = { 7,6,5,4,3,2,1 };
	vector<double> dvec(ivec.begin(), ivec.end());
	vector<double> dlist(ilist.begin(), ilist.end());
	cout << dvec.capacity() << " " << dvec.size() << " " << dvec[0] << endl;
	cout << dlist.capacity() << " " << dlist.size() << " " << dlist[0] << endl;
	for ( vector<double>::iterator it = dlist.begin(); it != dlist.end(); ++it)
	{
		cout << *it << " ";

}

	system("pause");
	return 0;
}