#include "my_head.h"
#include <iostream>
using namespace std;


void f( Employee &s)  //Ӧ��ʹ�����ã���Ϊû���µĶ����������ͨ�������ᵼ�µ��ÿ������캯����num��+1��
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