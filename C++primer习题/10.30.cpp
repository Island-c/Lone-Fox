#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>   //�������Ҫ�κ��ض�������һ��ʹ��vector��Ϊ����
using namespace std;
int main(int argc, char** argv)
{
	istream_iterator<int> in_iter(cin), eof;  //eof��β�������
	ostream_iterator<int> out_iter(cout, "  ");
//	vector<int> numbers(in_iter, eof); //ֱ�ӳ�ʼ��
	vector<int> numbers;
	while (in_iter != eof)
		numbers.push_back(*in_iter++);  // ��ȷд�� *in_iter++ 
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), out_iter);




	system("pause");
	return 0;
}