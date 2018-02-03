#include "my_head.h"
#include <iostream>
using namespace std;


void f( Employee &s)  //应当使用引用，因为没有新的对象，如果是普通参数，会导致调用拷贝构造函数，num会+1；
{
	s.print();
}

int main(int argc, char **argv)
{
	Employee E_1("are you ok ?  ");
	E_1.print();
	Employee E_2=E_1;
	E_2.print();
	f(E_1);





	system("pause");
	return 0;

}