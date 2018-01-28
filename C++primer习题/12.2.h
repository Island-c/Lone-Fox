#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>   //?
#include<initializer_list>  //C++11  初始化列表
using namespace std;
class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	//元素访问
	string &front();
	const string& front() const;
	string &back();
	const string& back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
	
};
StrBlob::StrBlob()  //默认构造函数
{
	data = make_shared <vector<string>>();
}

StrBlob::StrBlob(initializer_list<string> il) //拷贝构造函数
{
	data = make_shared<vector<string>>(il);
}

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

const string &StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()  //删除最后一个元素
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


#endif
