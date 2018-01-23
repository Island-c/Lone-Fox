#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<list>
using namespace std;

int main(int argc, char**argv)
{
	vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
	list<int> numbers_2;
	copy(numbers.crbegin() + 3, numbers.crend() - 2, back_inserter(numbers_2)); ///只有vector的迭代器可以直接加减数字........
	for (auto &num : numbers_2)
		cout << num << "  ";


	
	system("pause");
	return 0;
}