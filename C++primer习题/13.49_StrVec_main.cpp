#include "my_head.h"
#include <iostream>
using namespace std;

int main()
{
	StrVec my_vec{ "are","you","OK£¿"};
	StrVec my_vec_2;
	my_vec_2 = my_vec;
	StrVec my_vec_3;
	my_vec_3 = StrVec{"i am","very","ok"};
	system("pause");
 	return 0;

}

