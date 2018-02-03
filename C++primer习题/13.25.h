#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>   //?
#include<initializer_list>  //C++11  初始化列表
using namespace std;
class StrBlobPtr;

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	friend class StrBlobPtr; //在类StrBlobPtr中可以访问类StrBlob的私有成员data
public:
	StrBlob() //默认构造函数
	{
		data = make_shared <vector<string>>();
	}
	StrBlob(std::initializer_list<std::string> il) //构造函数
	{
		data = make_shared<vector<string>>(il);
	}

//拷贝控制：
	StrBlob(const StrBlob&) //拷贝构造函数
	{
		data = make_shared<std::vector<std::string>>(*(old.data));
	}
	StrBlob& operator= (const StrBlob&) //拷贝赋值运算符
	{
		data = make_shared<std::vector<std::string>>(*rstr.data);  //智能指针，所以不需要手动delete任何东西。
		return *this;
	}

public:
	size_type size() const { return data->size(); } //数据数量
	bool empty() const { return data->empty(); } //判空
	void push_back(const std::string &t) { data->push_back(t); } //增加数据
	void pop_back(); //移出数据

	//元素访问
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

void StrBlob::check(size_type i, const string& msg) const //检测是否为空
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string & StrBlob::front()  //返回第一个元素.
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const // const 版本
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string & StrBlob::back() //返回尾元素.
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string &StrBlob::back() const //const 版本
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()  //删除最后一个元素
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
	StrBlobPtr& incr(); //前缀递增



private:
	//若检查成功，返回一个shared_ptr 指向vector
	std::shared_ptr<std::vector<std::string>> 
		check(std::size_t, const std::string&) const; //确认shared_ptr是否被释放
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; //在数组中的当前位置。

};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock(); //对象不存在返回空shared_ptr, 对象存在 返回不空的~ 
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref()const  //提取元素
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() //递增curr
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;


}

#endif
