
#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	multimap<string, string> book;
	book.insert({ "��ӹ","�������" });
	book.insert({ "��ӹ","ӹӹӹӹӹӹ" });
	book.insert({ "����", "��������������" });
	book.insert({ "����", "��������������" });

	auto f = book.equal_range("��");

	book.erase(f.first, f.second); //��f����ʧ��ʱ��f.first��f.secondָ��ͬһ��Ԫ�أ���ʱ�������erase�ǰ�ȫ�ġ�


	for (auto &out : book)
	{
		cout << out.first << "    " << out.second << endl;
	}

	system("pause");
	return 0;
}