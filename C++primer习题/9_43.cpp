#include<iostream>
#include<string>
#include<vector>
using namespace std;

void string_replace(string &s, const string oldVal, const string newVal)
{
	auto iter_s = s.begin();
	while (iter_s != s.end())
	{
		auto iter_o= oldVal.begin();
		auto iter_ss = iter_s; //对s做个备份... 以ss作为s中字符的开始。
		while (*iter_ss == *iter_o )
		{
			iter_ss++;
			iter_o++;
			if (iter_o == oldVal.end() && iter_ss == s.end())
				break;
		}
		if (iter_o == oldVal.end())
		{
			iter_s = s.erase(iter_s, iter_ss);
			//iter_s = s.insert(iter_s, newVal);  不能直接插入一个string
			auto iter_n = newVal.end()-1;
			while (iter_n != newVal.begin()) {
				iter_s = s.insert(iter_s, *iter_n);
				iter_n--;
			}
			iter_s = s.insert(iter_s, *iter_n);

		}
		iter_s++;
	}
}



int main(int argc, char ** argv)

{

	string s("are you ok");
	string_replace(s, "ok", "fine");
	cout << s << endl;
	system("pause");
	return 0;
	
}