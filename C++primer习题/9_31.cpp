#include<iostream>
#include<list>
#include<forward_list>

using namespace std;

int main(int argc, char** argv)

{
	list<int> vi = { 1,2,3,4,5,6,7,8,9 };
	auto curr = vi.begin();
	while (curr != vi.end())
	{
		if (*curr & 1) { //����
			curr = vi.insert(curr, *curr);
			curr=curr++;  ///list û��+1 +2 �Ĳ���������������++������ ����ͨ�����++ʵ����ͬ��Ч����
		//	curr++;
		}
		else {
			curr = vi.erase(curr);
		}
	}
	for (curr = vi.begin(); curr != vi.end(); ++curr)
	{
		cout << *curr << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}