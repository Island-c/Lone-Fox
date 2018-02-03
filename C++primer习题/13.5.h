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
	HasPtr(const std::string &s = std::string) :ps(new std::string(s)), i(0) { cout << "���캯��" << endl; }
	HasPtr(const HasPtr& right);
	~HasPtr() { delete ps; }
public:
	HasPtr& operator =(const HasPtr &rhs);
private:
	std::string *ps;
	int i;
};


HasPtr::HasPtr(const HasPtr& right)  //�������캯��
{
	ps = new std::string(*(right.ps)); 
	i = right.i;
	cout << "�������캯�� " << endl;
}

HasPtr& HasPtr::operator= (const HasPtr& rhs)//������ֵ�����
{
	auto newps = new std::string(*rhs.ps); //����������ʱֱ���ͷ��ڴ棬�ȴ���һ����ʱ����
	delete ps; //�ͷ�Ҫ����λ�õ�ԭ���ڴ档
	ps = newps; //������
	i = rhs.i;
	cout << "������ֵ�����" << endl;
	return *this;
}

#endif
