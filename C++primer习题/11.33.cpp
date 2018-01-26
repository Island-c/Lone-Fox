#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<fstream>
#include<map>

using namespace std;

map<string, string> buildMap(ifstream &map_file);
void word_transform(ifstream& map_file, istream &input);
const string& transform(const string &s, const map<string, string> &m);

void word_transform(ifstream& map_file, istream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";  //������ǵ�һ�����ʣ�����Ҫ��һ���ո�
			cout << transform(word, trans_map);
		}
	}

}


map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key&&getline(map_file, value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);  //���Ե�0���ַ����ӵ�1���ַ������һ���ַ����п����� Ŀ���Ǻ���ǰ���ո�
		else
			throw runtime_error("no rule for" + key);
	}
	return trans_map;
}

const string& transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}



int main(int argc, char** argv)
{
	ifstream map_file(argv[1]);
	if (!map_file)
	{
		cerr << "error";
		exit(1);
	}
	word_transform(map_file, cin);



	system("pause");
	return 0;

}

