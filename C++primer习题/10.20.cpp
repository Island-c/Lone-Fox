#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char**argv)
{
	fstream in(argv[1]);
	if (!in)
	{
		cerr << "error" << endl;
		exit(1);
	}
	vector<string> vec;
	string my_string;
	while (in >> my_string)
	{
		vec.push_back(my_string);
	}

	auto i=count_if(vec.begin(), vec.end(), [](const string& str) {return str.size() >= 3; });
	for_each(vec.begin(), vec.end(), [](const string& str) {cout << str << endl; });
	cout << endl;

	cout << i << endl;



	system("pause");
	return 0;
}