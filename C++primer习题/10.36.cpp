#include<list>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

int main(int argc, char**argv)
{
	list<int> numbers;
	int n;
	while (cin >> n)
		numbers.push_back(n);
	ostream_iterator<int> out_iter(cout, "   ");
	auto f=find(numbers.crbegin(), numbers.crend(), 0);
	//copy(f.base(), numbers.end(), out_iter); //第二个参数为numbers.end() 时报错。
	//因为前面find函数中调用的是 crbegin crend.. 所以返回的f一定是 const_iterator, 必须用cend与之匹配。
	copy(f.base(), numbers.cend(), out_iter);
	
	system("pause");
	return 0;
}