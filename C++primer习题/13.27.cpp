#include "my_head.h"
#include <iostream>
using namespace std;

void fun(HasPtr p)
{
	p.test();
	HasPtr p_3=p;
//	p_3 = p;
	p.test();
	p_3.test();
}

int main(int argc, char **argv)
{
	HasPtr p_1("are you ok?");
	p_1.test();
	HasPtr p_2(p_1);
	p_1.test();
	p_2.test(); 
	fun(p_2);


	system("pause");
	return 0;

}