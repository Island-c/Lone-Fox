#include<iostream>
#include<vector>
#include<list>
 
using namespace std;

int main(int argc, char ** argv[])
{
	int ia[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	vector<int> ivec;
	list<int> ilist;

	ivec.assign(ia, ia + 10);
	ilist.assign(ia, ia + 10);

	auto iv = ivec.begin();

	while (iv != ivec.end())
	{
		if (*iv % 2 == 0)
		{
			iv = ivec.erase(iv);
		}
		else ++iv;
		
	}
	for (iv = ivec.begin(); iv != ivec.end(); ++iv)
		{
			cout << *iv << " ";
		}
	cout << endl;

	auto il = ilist.begin();
	while (il!=ilist.end())
	{
		if (*il %2== 1)
		{
			il = ilist.erase(il);
		}
		else ++il;
	}
	
	for (il = ilist.begin(); il != ilist.end(); ++il)
	{
		cout << *il << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}


