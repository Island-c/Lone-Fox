#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<char> v1{ 'a','b','c' };
	string my_string  (v1.data() , v1.size());  // data() : vector ��ģ��Ĺ�����Ա������
	//����ָ�������ڲ����ڴ洢����Ԫ�ص������ֱ��ָ�롣

	system("pause");
	return 0;
}