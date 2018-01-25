#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<algorithm>
#include<utility>
using namespace std;

int main(int argc, char** argv)
{
	map < string, vector<pair<string,string>> > family;
	string key_in;
	while (getline(cin, key_in))
	{
		istringstream record(key_in); //使用一个string流 ，将getline来的key_in分解成单独的单词处理。
		string first_name;
		string second_name;
		string birthday;
		//vector<string> second_names;
		//vector<string> birthdays;
		vector<pair<string, string>> people;
		record >> first_name;
		while (record >> second_name && record>>birthday)
		{
			people.push_back({ second_name, birthday });
		}
		family.insert({ first_name,people });
	}

	for (auto &one : family)
	{
		cout << one.first << "   ";
		for_each(one.second.begin(), one.second.end(), [](const pair<string, string> &one_1) {cout << one_1.first << " " << one_1.second<<"   "; });

		cout << endl;
	}


	system("pause");
	return 0;
}