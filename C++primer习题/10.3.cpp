#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec;
	fstream in(argv[1]);
	int a;
	while (in>>a)
	while(in)  //这样写会有一个很诡异的事情。。最后一个值被算了两次.
	{

		vec.push_back(a);
	}
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << sum << endl;



	system("pause");
	return 0;
}