#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<char> v1{ 'a','b','c' };
	string my_string  (v1.data() , v1.size());  // data() : vector 类模板的公共成员函数。
	//返回指向容器内部用于存储自身元素的数组的直接指针。

	system("pause");
	return 0;
}