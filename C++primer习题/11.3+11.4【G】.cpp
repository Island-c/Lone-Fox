#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>

using namespace std;

string& trans(string & s)
{
		for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] >= 65 && s[i] <= 90)	s[i] += 32;
		else if (s[i] == ',' || s[i] == '.') s.erase(i);
	}
	//莫名的错误写法
	int i = 0;
	for (auto &c : s)
	{
		if (c >= 65 && c <= 90)	c += 32;
		else if (c == ',' || c == '.') s.erase(i); //是因为这里 改变了s!
		//当一个Container执行了一次earse操作之后，原来用来遍历的iterator就失效了，其行为是不可预测的
		//如果只删掉第一个符合要求的元素，就在erase操作后加一个break ，阻止他继续遍历就好了。
		++i;
	}


	return s;

}

map<string, size_t> build_map(ifstream &in)
{
	map<string, size_t> words;
	string word;

	while (in >> word)
		++words[trans(word)];

	return words;
}



int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "error" << endl;
		system("pause");
		exit(1);
	}
	map<string, size_t> words = build_map(in);
	
	auto begin = words.begin();
	while (begin != words.end())
	{
		cout << (*begin).first << "   " << begin->second << endl;
		++begin;
	}

	system("pause");
	return 0;
}