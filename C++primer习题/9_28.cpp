#include<iostream>
#include<string>
#include<forward_list>

using namespace std;
bool func(forward_list<string> &ilist, string s_1, string s_2)
{
	auto prev = ilist.before_begin();
	auto curr = ilist.begin();
	while (curr != ilist.end())
	{
		if (*curr == s_1)
		{
			curr = ilist.insert_after(curr, s_2);

			return true;
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	ilist.insert_after(prev, s_2);
	return true;

}


int main(int argc, char** argv)
{
	forward_list<string> ilist = { "liu","chang","nice" };
	func(ilist, "chang", "xiao");
	for (auto iii = ilist.begin(); iii != ilist.end(); ++iii)
	{
		cout << *iii << endl;
	}


	system("pause");
	return 0;
}