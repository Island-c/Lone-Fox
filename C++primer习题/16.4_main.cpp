#include "my_head.h"

#include <iostream>
#include <vector>
#include<list>
#include <memory>
#include<string>
using namespace std;




int main(int argc, char** argv)
{

	vector<string> my_vec;
	list<string> my_list;
	string str;
	while (cin >> str)
	{
		my_vec.push_back(str);
		my_list.push_back(str);
	}

	cout << "输入要查找的词:" << endl;
	cin.clear();
	cin >> str;
	auto result_1 = my_find(my_vec.begin(), my_vec.end(), str);
	auto result_2 = my_find(my_list.begin(), my_list.end(), str);
	cout << *result_1 <<"      "<<*result_2<< endl;



	system("pause");
	return 0;

}
