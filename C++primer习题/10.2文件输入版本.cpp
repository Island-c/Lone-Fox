#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
	vector<string> vec;
	fstream in(argv[1]);
	if (!in) cerr << "error" << endl; 
	string a;
	while (in>>a)
	{
		
		vec.push_back(a);
	}
	cout << count(vec.begin(), vec.end(), "we") << endl;




	system("pause");
	return 0;
}