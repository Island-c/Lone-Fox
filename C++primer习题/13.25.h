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
		data = make_shared <vector<string>>();
	}
	StrBlob(std::initializer_list<std::string> il) //���캯��
	{
		data = make_shared<vector<string>>(il);
	}

//�������ƣ�
	StrBlob(const StrBlob&) //�������캯��
	{
		data = make_shared<std::vector<std::string>>(*(old.data));
	}
	StrBlob& operator= (const StrBlob&) //������ֵ�����
	{
		data = make_shared<std::vector<std::string>>(*rstr.data);  //����ָ�룬���Բ���Ҫ�ֶ�delete�κζ�����
		return *this;
	}

public:
	size_type size() const { return data->size(); } //��������
	bool empty() const { return data->empty(); } //�п�
	void push_back(const std::string &t) { data->push_back(t); } //��������
	void pop_back(); //�Ƴ�����

	//Ԫ�ط���
	string &front();
	const string& front() const;
	string &back();
	const string& back() const;
	StrBlobPtr begin() { return StrBlobPtr(*this); }
	StrBlobPtr end() { auto ret = StrBlobPtr(*this, data->size()); return ret; }

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;

};

void StrBlob::check(size_type i, const string& msg) const //����Ƿ�Ϊ��
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string & StrBlob::front()  //���ص�һ��Ԫ��.
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const // const �汾
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string & StrBlob::back() //����βԪ��.
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string &StrBlob::back() const //const �汾
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()  //ɾ�����һ��Ԫ��
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


class StrBlobPtr
{
public:

	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data) ,curr(sz){}
	std::string& deref() const;
	StrBlobPtr& incr(); //ǰ׺����



private:
	//�����ɹ�������һ��shared_ptr ָ��vector
	std::shared_ptr<std::vector<std::string>> 
		check(std::size_t, const std::string&) const; //ȷ��shared_ptr�Ƿ��ͷ�
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; //�������еĵ�ǰλ�á�

};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock(); //���󲻴��ڷ��ؿ�shared_ptr, ������� ���ز��յ�~ 
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref()const  //��ȡԪ��
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() //����curr
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;


}

#endif
