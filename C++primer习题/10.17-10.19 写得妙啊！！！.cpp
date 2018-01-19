#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>

using namespace std;

void string_print(const vector<string> str)
{
	for (auto &it : str)
	{
		cout << it << "   ";
	}
	cout << endl;
}
int main(int argc, char **argv)
{
	fstream in(argv[1]);
	if (!in)
	{
		cerr << "error" << endl;
		exit(1);
	}

	vector<string> vec;
	string my_string;
	while (in >> my_string)
		vec.push_back(my_string);
	cout << "原始序列：" << endl;
	string_print(vec);

	sort(vec.begin(), vec.end());
	cout << "sort后的序列：" << endl;
	string_print(vec);

	auto uniqued = unique(vec.begin(), vec.end());
	vec.erase(uniqued, vec.end());
	cout << "去重后序列：" << endl;
	string_print(vec);

	stable_sort(vec.begin(), vec.end(), [](const string &a,const string &b) {return a.size()< b.size(); });
	cout << "stable+lambda后的序列：" << endl;
	string_print(vec);

	int sx = 3;
	auto wc = partition(vec.begin(), vec.end(), [sx](const string& str) {return str.size() <= sx; });
	cout << "大于sx的元素们" << endl;
	for_each(wc, vec.end(), [](const string& str) { cout << str << "  "; });
	cout << endl;
	vec.erase(wc, vec.end());
	cout << "partition后的序列" << endl;
	string_print(vec);







	system("pause");
	return 0;
}


/*
argv[1].txt
//
aaa
aaaaaa
aa
a
a
aa
aa
aaa
aaaa
aaaaa
aaaaa
aaaa
bbb
bbbbbb
bb
b
b
bb
bb
bbb
bbbb

*/