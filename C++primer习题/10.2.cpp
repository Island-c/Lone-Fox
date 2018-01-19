#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> vec;
	while (cin)
	{
		string a;
		cin >> a;
		vec.push_back(a);
	}
	cout << count(vec.begin(), vec.end(), "we") << endl;




	system("pause");
	return 0;
}