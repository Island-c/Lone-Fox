#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<string> ivec;
	string my_str;
	auto ii = ivec.begin();
	while (cin >> my_str)
		ii=ivec.insert(ii, my_str); //����ѷ���ֵ��������������Ϊ����Ԫ�غ� ԭ���ĵ�������ʧЧ��
	for (auto i = ivec.cbegin(); i != ivec.end(); ++i)
	{
		cout << *i << endl;
	}

	system("pause");
	return 0;
}