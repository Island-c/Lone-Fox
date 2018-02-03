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
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) ,use(new std::size_t(0)){ std::cout << "构造函数" << endl; }
	HasPtr(const HasPtr& right) :ps(right.ps), i(right.i), use(right.use) { ++*use; cout << "拷贝构造函数" << endl; }; //拷贝构造函数
	~HasPtr(); //析构函数
	HasPtr& operator =(const HasPtr &);   //拷贝赋值运算符
	std::string operator *() { return *ps; }  //解引用
	HasPtr& operator =(const string &str) { *ps = str; return *this; } //接受一个string参数。
public:
	void test() { cout << *ps << "   " << i << "    " << *use << endl; }
private:
	std::string *ps;
	int i; //
	std::size_t *use; //引用计数
};




HasPtr& HasPtr::operator= (const HasPtr& right)//拷贝赋值运算符
{
	++*right.use; //只能对左值使用后置的++
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	use = right.use;
	ps = right.ps;
	i = right.i;
	std::cout << "拷贝赋值运算符" << endl;
	return *this;
}

HasPtr::~HasPtr()
{
	if (--*use == 0)  //当前对象销毁时才会执行析构，引用次数会减1， 所以要先-- ，再判断是否为0。
	{
		delete ps;
		delete use;
	}
	cout << "析构函数" << endl;
}
#endif
