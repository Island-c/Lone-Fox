#include "my_head.h"
#include <iostream>
using namespace std;

//void fun(const HasPtr & p)
void fun(const HasPtr  p)  //如果形参不是引用，则会调用一次拷贝构造函数。
// 所以 如果拷贝构造函数中的形参不是引用，则会无限循环调用拷贝构造函数。
{
	HasPtr my_HasPtr_3;
	my_HasPtr_3 = p;


}

int main(int argc, char **argv)
{
	HasPtr my_HasPtr("are you ok? OUO ");
	HasPtr my_HasPtr_2(my_HasPtr);
	fun(my_HasPtr_2);



	system("pause");
	return 0;

}