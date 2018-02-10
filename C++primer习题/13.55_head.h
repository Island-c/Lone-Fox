#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>   //?
#include<initializer_list>  //C++11  ��ʼ���б�
using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	friend class StrBlobPtr; //����StrBlobPtr�п��Է�����StrBlob��˽�г�Աdata
public:
	StrBlob() //Ĭ�Ϲ��캯��
	{
		data = make_shared <vector<string>>(); //��ָ��
	}
	StrBlob(std::initializer_list<std::string> il) //���캯��
	{
		data = make_shared<vector<string>>(il);
	}

	//�������ƣ�
	StrBlob(const StrBlob& old) //�������캯��
	{
		data = make_shared<std::vector<std::string>>(*(old.data)); //��Ϊ������ָ�룬���Բ���Ҫ�ֶ��ͷ��ڴ�.
	}
	StrBlob& operator= (const StrBlob& rstr) //������ֵ�����
	{
		data = make_shared<std::vector<std::string>>(*rstr.data);  //����ָ�룬���Բ���Ҫ�ֶ�delete�κζ�����
		return *this;
	}

public:
	size_type size() const { return data->size(); } //��������
	bool empty() const { return data->empty(); } //�п�
	void push_back(const std::string &t) { data->push_back(t); } //�������� data��������һ��vector��������õ���vector��push_back .
	void push_back(const std::string &&t) { data->push_back(std::move(t)); } //push_back����ֵ���ð汾.
	void pop_back(); //�Ƴ�����

	//Ԫ�ط���
	string &front();
	const string& front() const;
	string &back();
	const string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data;

	void check(size_type i, const std::string &msg) const;

};


class StrBlobPtr
{
public:

	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr(); //ǰ׺����

private:
	//�����ɹ�������һ��shared_ptr ָ��vector
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const; //ȷ��shared_ptr�Ƿ��ͷ�
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; //�������еĵ�ǰλ�á�

};

#endif
