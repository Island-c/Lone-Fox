#include<list>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

int main(int argc, char**argv)
{
	list<int> numbers;
	int n;
	while (cin >> n)
		numbers.push_back(n);
	ostream_iterator<int> out_iter(cout, "   ");
	auto f=find(numbers.crbegin(), numbers.crend(), 0);
	//copy(f.base(), numbers.end(), out_iter); //�ڶ�������Ϊnumbers.end() ʱ����
	//��Ϊǰ��find�����е��õ��� crbegin crend.. ���Է��ص�fһ���� const_iterator, ������cend��֮ƥ�䡣
	copy(f.base(), numbers.cend(), out_iter);
	
	system("pause");
	return 0;
}