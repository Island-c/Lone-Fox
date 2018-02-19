#include "my_head.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	vector<int> my_vec{ 0,1,2,3,4,5,6,7,8,9 };
	Blob<int> squares_1(my_vec.begin(),my_vec.end());
	Blob<int> squares_2 = { 0,1,2,3,4,5,6,7,8,9 };
	BlobPtr<int> ptr(squares_1, 3);
	if (squares_1 == squares_2)
		cout << ptr.deref() << endl;
	cout << squares_2[3] << endl;

	system("pause");
	return 0;

}
