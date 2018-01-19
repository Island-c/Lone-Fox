#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const string &s)
{
	///过程略
	return true;
}

int main(int argc, char** argv)
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	if (argc != 2)
	{
		cerr << "please tell me file name" << endl;
		return -1;
	}


	ifstream in(argv[1]);
	if (!in)

	{
		cerr << "can't open this file" << endl;
		return -1;
	}

	while (getline(in, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	ostringstream os;
	for (const auto &entry : people) //代替遍历器
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << nums << " ";
			}
			else formatted << " " << format(nums);

		}
		if (badNums.str().empty())
			os << entry.name << " " << formatted.str() << endl;
		else
			cerr << "imput error:" << badNums.str() << endl;



	}
	cout << os.str() << endl;
	system("pause");
	return 0; 
}