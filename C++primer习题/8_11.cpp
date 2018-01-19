#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main(int argc, char** argv)
{
	string line, word;
	vector<PersonInfo> vec;
	istringstream record;
	while (getline(cin, line))
	{
		record.clear();
		record.str(line);
		PersonInfo new_person;
		record >> new_person.name;
		while (record >> word)
		{
			new_person.phones.push_back(word);

		}
		vec.push_back(new_person);

	}

	system("pause");
	return 0;

}
