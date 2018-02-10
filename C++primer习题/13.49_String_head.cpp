#include "my_head.h"

std::allocator<char> String::alloc; //必须声明alloc属于哪个类！

pair<char *, char *>  String::alloc_n_copy(const char *l, const char *r) // 分配空间。
{
	auto newdata=alloc.allocate(r - l); //分配空间

	return { newdata, uninitialized_copy(l,r,newdata) }; //拷贝对象
}
void String::range_build(const char* l, const char* r) //两个成员函数采用了相同的操作，所以写成一个公共函数。
{
	auto newString = alloc_n_copy(l, r);
	elements = newString.first;
	end = newString.second;
}

void String::free() //销毁元素和收回空间
{
	if (elements) //elements不是 nullptr
	{
		std::for_each(elements, end, [](char &r) {alloc.destroy(&r); });  //删除分配空间中的每个元素
		alloc.deallocate(elements, end-elements);  //收回分配的空间
	}

}


String::String(const char * c) //构造函数
{
	//char* s1 = const_cast<char*> (c);  //强制类型转换，去const 。 否则不能赋值。
	const char *s1 = c;
	while (*s1) ++s1;
	range_build(c, s1);
	cout << "普通构造函数" << endl;
}

String::String(const String& s)
{
	/*auto newStr = alloc_n_copy(s.elements, s.end);
	//free(); //拷贝构造函数不需要free内存，因为执行这个函数的，都是第一次定义的对象。
	elements = newStr.first;
	end = newStr.second;*/
	range_build(s.elements, s.end);
	cout << "拷贝构造函数" << endl;
}

String::String(String && s)
{
	range_build(std::move(s.elements), std::move(s.end));
	cout << "移动构造函数" << endl;

}
String& String::operator=(String && s)
{
	auto newStr = alloc_n_copy(std::move(s.elements), std::move(s.end));
	free();
	elements = newStr.first;
	end = newStr.second;
	cout << "移动赋值运算符" << endl;
	return *this;


}

String& String::operator= (const String & s) //拷贝赋值运算符， 要free左侧的对象.
{
	auto newStr = alloc_n_copy(s.elements, s.end);
	free();
	elements = newStr.first;
	end = newStr.second;
	cout << "拷贝赋值运算符" << endl;
	return *this;
}

String::~String()
{
	cout << "析构函数" << endl;
	free();
}