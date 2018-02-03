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

class Employee
{
public:
	Employee() :Name(" "), Number(++Numb) { std::cout << "普通默认构造函数" << endl; }
	Employee(const string n) :Name(n), Number(++Numb) { std::cout << "普通构造函数" << endl; }  //普通构造函数
	Employee(const Employee &n); //拷贝构造函数
public:
	Employee& operator= (const Employee & e); //拷贝赋值运算符
	void print() {
		std::cout << Name << "   " << Number << endl;
	}

private:
	std::string Name;
	int Number;
public:
	static int Numb;
};

int Employee::Numb = 10000000;

Employee::Employee(const Employee &n)
{
	Name = n.Name;
	Number = (++Numb);
	std::cout << "拷贝构造函数" << endl;
}
Employee& Employee::operator= (const Employee &e)
{
	Name = e.Name;
	Number = (++Numb);
	std::cout << "拷贝赋值运算符" << endl;

	return *this;
}

#endif
