#ifndef MY_HEAD_H
#define MY_HEAD_H

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
	HasPtr(const std::string &s = std::string) :ps(new std::string(s)), i(0) { cout << "构造函数" << endl; }
	HasPtr(const HasPtr& right);
	~HasPtr() { delete ps; }
public:
	HasPtr& operator =(const HasPtr &rhs);
private:
	std::string *ps;
	int i;
};


HasPtr::HasPtr(const HasPtr& right)  //拷贝构造函数
{
	ps = new std::string(*(right.ps)); 
	i = right.i;
	cout << "拷贝构造函数 " << endl;
}

HasPtr& HasPtr::operator= (const HasPtr& rhs)//拷贝赋值运算符
{
	auto newps = new std::string(*rhs.ps); //避免自身拷贝时直接释放内存，先创建一个临时量。
	delete ps; //释放要拷贝位置的原有内存。
	ps = newps; //拷贝。
	i = rhs.i;
	cout << "拷贝赋值运算符" << endl;
	return *this;
}

#endif
