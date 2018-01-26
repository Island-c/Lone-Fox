
#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	multimap<string, string> book;
	book.insert({ "金庸","金金金金金金" });
	book.insert({ "金庸","庸庸庸庸庸庸" });
	book.insert({ "古龙", "咕咕咕咕咕咕咕" });
	book.insert({ "古龙", "龙龙龙龙龙龙龙" });

	auto f = book.equal_range("古");

	book.erase(f.first, f.second); //当f查找失败时，f.first和f.second指向同一个元素，此时对其调用erase是安全的。


	for (auto &out : book)
	{
		cout << out.first << "    " << out.second << endl;
	}

	system("pause");
	return 0;
}