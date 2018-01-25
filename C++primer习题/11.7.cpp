#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	
	map < string, vector<string>> family;
	string key_in;
	while (getline(cin, key_in))
	{
		istringstream record(key_in); //使用一个string流 ，将getline来的key_in分解成单独的单词处理。
		string first_name;
		string second_name;
		vector<string> second_names;
		
		record >> first_name;
		while (record>>second_name)
		{	
			second_names.push_back(second_name);
		}
		family.insert({ first_name,second_names });
	}
	
	for (auto &one : family)
	{
		cout << one.first << "   ";
		for_each(one.second.begin(), one.second.end(), [](const string& str) {cout << str<<" "; });
		cout << endl;
	}


	system("pause");
	return 0;
}