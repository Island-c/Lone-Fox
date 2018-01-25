#include<iostream>
#include<utility>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char ** argv)
{
	
	vector<pair<string,int>> my_pair;
	string str;
	int i;
	cin >> str;
	cin >> i;
	//my_pair.push_back({ str,i });
	//my_pair.push_back(pair<string, int>(str, i));
	my_pair.push_back(make_pair(str,i));
	for (auto &out : my_pair)
	{
		cout << out.first << "   " << out.second << endl;
	}

	system("pause");
	return 0;
}