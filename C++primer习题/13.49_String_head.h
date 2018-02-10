#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<initializer_list>
using namespace std;

class String
{
public:
	String() :elements(nullptr), end(nullptr) { cout << "默认构造函数" << endl; }
	String(const char*);
	
	String(const String&);
	String(String &&); //移动构造函数
	String &operator =(const String&);
	String &operator=(String &&);
	~String();

	const char* begin()const { return elements; } //返回指向首元素的指针 ，非const对象可以调用const成员函数或非const成员函数
	size_t size() const { return end - elements; } //大小
	size_t length() const { return end - elements - 1; } //长度

	void test()
	{
		char* iter = elements;
		while (iter !=end)
		{
			cout << *(iter++) << endl;
		}
	}

private:
	static std::allocator<char> alloc;
	std::pair<char *, char *> alloc_n_copy(const char *, const char *); 
	void free();
	void range_build(const char *,const  char *);
	 

private:
	
	char *elements;
	char *end;

};
#endif
