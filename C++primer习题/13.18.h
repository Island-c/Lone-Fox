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
	Employee() :Name(" "), Number(++Numb) { std::cout << "��ͨĬ�Ϲ��캯��" << endl; }
	Employee(const string n) :Name(n), Number(++Numb) { std::cout << "��ͨ���캯��" << endl; }  //��ͨ���캯��
	Employee(const Employee &n); //�������캯��
public:
	Employee& operator= (const Employee & e); //������ֵ�����
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
	std::cout << "�������캯��" << endl;
}
Employee& Employee::operator= (const Employee &e)
{
	Name = e.Name;
	Number = (++Numb);
	std::cout << "������ֵ�����" << endl;

	return *this;
}

#endif
