#include<iostream>
#include<list>
#include<forward_list>
#include<vector>
#include<windows.h>

using namespace std;

int main(int argc, char** argv)

{
	int a = 0;
	vector<int> vi ;
	while (a < 500)
	{
		vi.push_back(3);
		cout << "size£º" << vi.size() << "  " << "capacity" << vi.capacity() << endl;
		++a;
		Sleep(50);
	}



	system("pause");
	return 0;
}