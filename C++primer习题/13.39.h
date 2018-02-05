#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<initializer_list>
using namespace std;
class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){} //构造函数
	StrVec(initializer_list<string> il);
	StrVec(const StrVec&);  //拷贝构造函数
	StrVec& operator =(const StrVec&); //拷贝赋值运算符
	~StrVec(); //析构函数

public:
	void push_back(const std::string&); //添加元素
	size_t size() const { return first_free - elements; } //已占用空间大小
	size_t capacity()const { return cap - elements; } //总空间大小
	void reverse(size_t n) { if (n > capacity()) reallocate(); };  //如果空间不够用，则重新分配空间。
	void resize(size_t);
	void resize(size_t, const std::string &);
	

	std::string *begin() const { return elements; }
	std::string *end()const { return first_free; }


private:
	static std::allocator<std::string> alloc; //分配元素
	// 被添加元素的函数使用
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate(); //确保有足够的空间
	}
	//工具函数，被拷贝构造函数、赋值运算符、和析构函数使用。
	std::pair<std::string*, std::string *> alloc_n_copy(const std::string*, const std::string*);
	void free(); //销毁元素 释放内存
	void reallocate(); //获得更多空间并拷贝已有函数
	//数据成员
	std::string *elements;  //首元素
	std::string *first_free; //第一个空闲元素
	std::string *cap;  //尾后位置

};


#endif
