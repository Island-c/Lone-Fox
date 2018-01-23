#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>   //如果不需要任何特定操作，一般使用vector作为容器
using namespace std;
int main(int argc, char** argv)
{
	istream_iterator<int> in_iter(cin), eof;  //eof：尾后迭代器
	ostream_iterator<int> out_iter(cout, "  ");
//	vector<int> numbers(in_iter, eof); //直接初始化
	vector<int> numbers;
	while (in_iter != eof)
		numbers.push_back(*in_iter++);  // 正确写法 *in_iter++ 
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), out_iter);




	system("pause");
	return 0;
}