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
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) ,use(new std::size_t(0)){ std::cout << "���캯��" << endl; }
	HasPtr(const HasPtr& right) :ps(right.ps), i(right.i), use(right.use) { ++*use; cout << "�������캯��" << endl; }; //�������캯��
	~HasPtr(); //��������
	HasPtr& operator =(const HasPtr &);   //������ֵ�����
	std::string operator *() { return *ps; }  //������
	HasPtr& operator =(const string &str) { *ps = str; return *this; } //����һ��string������
public:
	void test() { cout << *ps << "   " << i << "    " << *use << endl; }
private:
	std::string *ps;
	int i; //
	std::size_t *use; //���ü���
};




HasPtr& HasPtr::operator= (const HasPtr& right)//������ֵ�����
{
	++*right.use; //ֻ�ܶ���ֵʹ�ú��õ�++
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	use = right.use;
	ps = right.ps;
	i = right.i;
	std::cout << "������ֵ�����" << endl;
	return *this;
}

HasPtr::~HasPtr()
{
	if (--*use == 0)  //��ǰ��������ʱ�Ż�ִ�����������ô������1�� ����Ҫ��-- �����ж��Ƿ�Ϊ0��
	{
		delete ps;
		delete use;
	}
	cout << "��������" << endl;
}
#endif
