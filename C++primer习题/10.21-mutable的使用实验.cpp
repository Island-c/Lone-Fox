#include<iostream>
#include<algorithm>

using namespace std;
int main(int argc, char** argv)
{
	int v = 1;
	auto f=[v](int a) mutable {++v}; //mutable  ��ȷ��
//	auto f = [=](int a) {++v; };  //������ʾ++v ���ʽ�����ǿ��޸ĵ���ֵ��
//	auto f = [&](int a) {++v; };  //���ò��� ��дmutable Ҳ�����޸Ĳ���ֵ
	cout << v << endl;

	system("pause");
	return 0;
}