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

class HasPtr
{
public:
	friend void swap(HasPtr &l, HasPtr &r);
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) { std::cout << "构造函数" << endl; }
	HasPtr(const HasPtr& right);
	~HasPtr() { delete ps; }
public:
	HasPtr& operator =(const HasPtr &rhs);
	bool operator <( HasPtr &r) {  cout << "aaa" << endl;return *ps < *r.ps;  }
	//bool operator< (const HasPtr& l, const HasPtr &r) { cout << "aaa" << endl; return *l.ps < *r.ps; }

private:
	std::string *ps;
	int i;
};


HasPtr::HasPtr(const HasPtr& right)  //拷贝构造函数
{
	ps = new std::string(*(right.ps));
	i = right.i;
	std::cout << "拷贝构造函数 " << endl;
}
 inline void swap(HasPtr &l, HasPtr &r)  //声明为inline ，高效。
{
	using std::swap;
	swap(l.ps, r.ps);
	std::swap(l.i, r.i);
	cout << "调用swap,交换：" << l.ps << "  " << r.ps << endl;
}
HasPtr& HasPtr::operator= (const HasPtr& rhs)//拷贝赋值运算符
{
	auto newps = new std::string(*rhs.ps); //为了避免自拷贝出现先delete的情况。要先创建一个临时值。
	delete ps; //释放左值原来的内存
	ps = newps; //拷贝
	i = rhs.i;
	std::cout << "拷贝赋值运算符" << endl;
	return *this;
}

#endif
