#include "my_head.h"

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

StrBlobPtr StrBlob::begin()
{
	{ return StrBlobPtr(*this); }
}

StrBlobPtr StrBlob::end()
{
	 auto ret = StrBlobPtr(*this, data->size());
	 return ret; 
}
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