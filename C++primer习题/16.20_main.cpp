#include "my_head.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<string>
using namespace std;


template<typename IT>
void print(IT iter1, IT iter2)
{
	for (iter1;iter1!=iter2;++iter1)
	{
		cout <<*iter1 << endl; //��at�����±������������ʱ�������쳣��ʾ�����������
	}
}

int main(int argc, char** argv)
{
	vector<int> my_vec{ 1,2,3,4,5,6,67 };
	print(my_vec.begin(),my_vec.end());

	system("pause");
	return 0;

}
