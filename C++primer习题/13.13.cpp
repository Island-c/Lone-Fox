#include "my_head.h"
#include <iostream>
using namespace std;

//void fun(const HasPtr & p)
void fun(const HasPtr  p)  //����ββ������ã�������һ�ο������캯����
// ���� ����������캯���е��ββ������ã��������ѭ�����ÿ������캯����
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