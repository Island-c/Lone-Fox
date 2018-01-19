#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char **argv)

{
	vector<int> vec = {1,2,3,3,3,3,3,1,1,2,2,2,1};
	list<int> li;

	//unique_copy(vec.begin(), vec.end(), back_inserter(li));
	copy(vec.begin(), vec.end(), back_inserter(li));
	for (auto &i : li)
		cout << i << "   ";
	cout << endl;

	system("pause");
	return 0;
}