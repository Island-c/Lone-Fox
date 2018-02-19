#include "my_head.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<string>
using namespace std;

template<typename T> 
void print(const T& t)
{
	for (typename T::size_type i = 0; i < t.size(); ++i)
	{
		cout <<t.at(i) << endl; //用at代替下标运算符。出错时，会有异常提示，不会崩溃。
	}
}

int main(int argc, char** argv)
{
	vector<int> my_vec{ 1,2,3,4,5,6,67 };
	print(my_vec);

	system("pause");
	return 0;

}
