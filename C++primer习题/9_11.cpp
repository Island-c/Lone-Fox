#include<iostream>
#include<vector>

using namespace std;



int main()
{
	vector<int> ilist1;
	vector<int> ilist2(ilist1);
	vector<int> ilist = { 1,2,3,4,5 };
	vector<int> ilist3(ilist1.begin()) + 2, ilist.end() - 1);
	vector<int> ilist4(7); //默认初始化， 包含七个元素，每个元素都进行缺省的值初始化。
	vector<int> ilist5(7, 3); //七个元素 每个赋值3



	system("pause");
	return 0;
}