#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char ** argv)
{
	int line_code=0;
	ifstream in(argv[1]); //使用文件输入。
	if (!in) {
		cerr << "error";
		exit(1);
	}
	map<string, vector<int>> word_line;
	
	string line;
	while (getline(in, line))
	{
		line_code++;
		istringstream line_in(line); 
		string word;
		while (line_in >> word)
			word_line[word].push_back(line_code);
	}
	for (auto &out : word_line)
	{
		cout << out.first << " ";
		for_each(out.second.begin(), out.second.end(), [](const int & a) {cout << a << " "; });
		cout<< endl;
	}




	system("pause");
	return 0;
}