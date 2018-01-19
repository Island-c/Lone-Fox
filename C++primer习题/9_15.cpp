#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<int> a1 = { 1,2,3,4,5,6 };
	vector<int> a2 = { 1,2,3,4,5,7 };
	vector<int> a3 = { 1,2,3,4,9 };

	cout << (a1 > a3 ? "a1>a3" : "a1<a3") << endl;
	cout <<( a1 > a2 ? "a1>a2" : "a1<a2" )<< endl;
	if (a1 < a3) cout << 000000000 << endl;
	system("pause");
	return 0;


}