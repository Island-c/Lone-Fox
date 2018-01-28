//#include "my_head.h"
#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;
vector<int> *build()  //动态分配一个 vector<int>
{
	return  new vector<int>;
}

vector<int> * func(vector<int> *my_vector, istream & in)  //使用标准输入向vector内添加元素
{
	int i;
	while (in >> i)
	{
		my_vector->push_back(i);
	}
	return my_vector;
}

void print(const vector<int> * const my_vector)	//遍历输出。
{
	for (auto &out : (*my_vector))
	{
		cout << out << endl;
	}
	delete my_vector;  //释放内存。！
}

int main(int argc, char** argv)
{
	print(func(build(), cin)); // test




	system("pause");
	return 0;
}