#include<iostream>
#include<vector>

using namespace std;



int main()
{
	vector<int> ilist1;
	vector<int> ilist2(ilist1);
	vector<int> ilist = { 1,2,3,4,5 };
	vector<int> ilist3(ilist1.begin()) + 2, ilist.end() - 1);
	vector<int> ilist4(7); //Ĭ�ϳ�ʼ���� �����߸�Ԫ�أ�ÿ��Ԫ�ض�����ȱʡ��ֵ��ʼ����
	vector<int> ilist5(7, 3); //�߸�Ԫ�� ÿ����ֵ3



	system("pause");
	return 0;
}