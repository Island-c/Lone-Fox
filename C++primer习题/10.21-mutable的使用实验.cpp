#include<iostream>
#include<algorithm>

using namespace std;
int main(int argc, char** argv)
{
	int v = 1;
	auto f=[v](int a) mutable {++v}; //mutable  正确。
//	auto f = [=](int a) {++v; };  //错误，提示++v 表达式必须是可修改的左值。
//	auto f = [&](int a) {++v; };  //引用捕获 不写mutable 也可以修改捕获值
	cout << v << endl;

	system("pause");
	return 0;
}