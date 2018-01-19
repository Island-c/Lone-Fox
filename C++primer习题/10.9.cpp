#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void print(vector<string> &vec)
{
	for (const auto &iter : vec)
	{
		cout << iter << "  ";
	}
	cout << "   size: " << vec.size() << endl;

}


void elimDups(vector<string> &vec)
{
	sort(vec.begin(), vec.end());
	print(vec);
	auto end_unique = unique(vec.begin(), vec.end());
	print(vec);
	vec.erase(end_unique, vec.end());

}


int main(int argc, char ** argv)
{
	vector<string> vec;
	string a;
	while (cin >> a)
		vec.push_back(a);
	print(vec);
	elimDups(vec);
	print(vec);

	system("pause");
	return 0;
}