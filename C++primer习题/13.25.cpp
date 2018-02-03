#include "my_head.h"
#include <iostream>
using namespace std;



int main(int argc, char **argv)
{
	StrBlob str_1{"are","you","ok?"};

	StrBlobPtr ptr_2(str_1,2);
	cout << ptr_2.deref();



	system("pause");
	return 0;

}