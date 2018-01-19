#include<iostream>
#include<algorithm>
#include<Windows.h>
using namespace std;
int main()
{
	int a = 10;
	auto f = [&]() ->bool { if (a >= 0) { a--; return true; } else return false; };
	while (1)
	{
		auto i = f();
		cout << i << endl;
		Sleep(1000);
	}


	system("pasue");
	return 0;
}