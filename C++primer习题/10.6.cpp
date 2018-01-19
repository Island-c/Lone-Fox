#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
	
	fstream in(argv[1]);
	if (!in) {
		cerr << "error" << endl;
		exit(0);
	}

	vector<int> vec;
	int a;
	while (in >> a)
	{
		vec.push_back(a);
	}

	//fill(vec.begin(), vec.end(), 0);
	fill_n(vec.begin(), vec.size(), 0);
	auto iter = vec.begin();
	while (iter != vec.end())
	{
		cout << *iter << endl;
		iter++;
	}



	system("pause");
	return 0;
}