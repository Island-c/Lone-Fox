#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<utility>
#include<map>
#include<string>
using namespace std;

class test
{
public:
	test():i(0){}
	test(const test& t);

public:
	void print();

private:
	int i;

};

test::test(const test& t) //可能实现方式不同，导致和课后题答案不一致。
{
	i = t.i + 1;
}

void test::print()
{
	std::cout << i << endl;
}
#endif
