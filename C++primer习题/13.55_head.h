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
		data = make_shared <vector<string>>(); //空指针
	}
	StrBlob(std::initializer_list<std::string> il) //构造函数
	{
		data = make_shared<vector<string>>(il);
	}

	//拷贝控制：
	StrBlob(const StrBlob& old) //拷贝构造函数
	{
		data = make_shared<std::vector<std::string>>(*(old.data)); //因为是智能指针，所以不需要手动释放内存.
	}
	StrBlob& operator= (const StrBlob& rstr) //拷贝赋值运算符
	{
		data = make_shared<std::vector<std::string>>(*rstr.data);  //智能指针，所以不需要手动delete任何东西。
		return *this;
	}

public:
	size_type size() const { return data->size(); } //数据数量
	bool empty() const { return data->empty(); } //判空
	void push_back(const std::string &t) { data->push_back(t); } //增加数据 data解引用是一个vector，这里调用的是vector的push_back .
	void push_back(const std::string &&t) { data->push_back(std::move(t)); } //push_back的右值引用版本.
	void pop_back(); //移出数据

	//元素访问
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
	StrBlobPtr& incr(); //前缀递增

private:
	//若检查成功，返回一个shared_ptr 指向vector
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const; //确认shared_ptr是否被释放
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; //在数组中的当前位置。

};

#endif
