#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;

bool shorter(const string &str,int sz)
{
	return str.size() >= sz;
}

int main(int argc, char** argv)
{
	fstream in(argv[1]);
	if (!in) {
		cerr << "error" << endl;
		exit(1);
	}

	vector<string> vec;
	string my_string;
	int sz = 5;
	while (in >> my_string)
		vec.push_back(my_string);

	auto sho = bind(shorter, _1,sz);
	for_each(vec.begin(), vec.end(), [](const string& str) {cout << str << "  "; });
	cout << endl;

	auto i=find_if(vec.begin(), vec.end(), sho);
	cout << *i << endl;
	system("pause");
	return 0;

	

}

