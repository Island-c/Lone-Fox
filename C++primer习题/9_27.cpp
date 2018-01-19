#include<iostream>
#include<forward_list>
using namespace std;

int main(int argc, char** argv)
{
	forward_list<int> iflist = { 1,2,3,4,5,6,7,8,9 };

	auto prev = iflist.before_begin();
	auto curr = iflist.begin();

	while (curr != iflist.end())
	{
		if (*curr % 2)
		{
			curr = iflist.erase_after(prev);  ///只能erase_after
			//这步操作之后，prev不变，curr为原先curr的下一个元素。所以prev的下个元素自动变为curr
		}
		else
		{
			prev = curr;
			curr++;
		}
	}
	for (curr = iflist.begin(); curr != iflist.end(); ++curr)
	{
		cout << *curr << endl;
	}


	system("pause");
	return 0;
}