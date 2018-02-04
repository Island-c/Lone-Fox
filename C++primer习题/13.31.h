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
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) { std::cout << "���캯��" << endl; }
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


HasPtr::HasPtr(const HasPtr& right)  //�������캯��
{
	ps = new std::string(*(right.ps));
	i = right.i;
	std::cout << "�������캯�� " << endl;
}
 inline void swap(HasPtr &l, HasPtr &r)  //����Ϊinline ����Ч��
{
	using std::swap;
	swap(l.ps, r.ps);
	std::swap(l.i, r.i);
	cout << "����swap,������" << l.ps << "  " << r.ps << endl;
}
HasPtr& HasPtr::operator= (const HasPtr& rhs)//������ֵ�����
{
	auto newps = new std::string(*rhs.ps); //Ϊ�˱����Կ���������delete�������Ҫ�ȴ���һ����ʱֵ��
	delete ps; //�ͷ���ֵԭ�����ڴ�
	ps = newps; //����
	i = rhs.i;
	std::cout << "������ֵ�����" << endl;
	return *this;
}

#endif
