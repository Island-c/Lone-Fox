#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;
int main(int argc, char ** argv)
{
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "error";
		exit(1);
	}
	string word;
	map<string, size_t> words;
	while (in >> word)
	{
		auto ret = words.insert({word,1}); //insert的对象必须和map<> 中的类型和数量保持一致。
		// ret是一个pair类型， first是一个迭代器，指向插入的元素（或者已经存在的那个和要插入的元素一样的元素）
		//second是一个bool类型， 若插入成功，则值为true ，若map中已存在该关键字，插入不成功，则返回false。 
		if (!ret.second)//已经存在该word.
		{
			++(*(ret.first)).second; 
		}
	}

	for (auto & out : words)
	{
		cout << out.first << "  " << out.second << endl;
	}


	system("pause");
	return 0;
}