#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec;
	while (cin)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cout << count(vec.begin(), vec.end(), 3) << endl;




	system("pause");
	return 0;
}