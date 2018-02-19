#include"_head.h" 
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<string>
using namespace std;

template <typename T1,typename T2>
auto sum(T1 a, T2 b) ->decltype(a + b)
{
	return a + b;
}

int main(int argc, char** argv)
{
	
	auto a = sum(1, 1);
	cout << a << "  " << sizeof(a) << endl; //int 
	auto b = sum(1, 1.1);
	cout << b << "  " << sizeof(b) << endl; //double
	auto c = sum(1, 1.1f); 
	cout << c << "  " << sizeof(c) << endl; //float


	system("pause");
	return 0;

}
