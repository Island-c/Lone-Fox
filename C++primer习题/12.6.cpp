//#include "my_head.h"
#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;
vector<int> *build()  //��̬����һ�� vector<int>
{
	return  new vector<int>;
}

vector<int> * func(vector<int> *my_vector, istream & in)  //ʹ�ñ�׼������vector�����Ԫ��
{
	int i;
	while (in >> i)
	{
		my_vector->push_back(i);
	}
	return my_vector;
}

void print(const vector<int> * const my_vector)	//���������
{
	for (auto &out : (*my_vector))
	{
		cout << out << endl;
	}
	delete my_vector;  //�ͷ��ڴ档��
}

int main(int argc, char** argv)
{
	print(func(build(), cin)); // test




	system("pause");
	return 0;
}