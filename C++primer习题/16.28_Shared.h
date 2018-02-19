#ifndef _SHARED_H
#define _SHARED_H
#include <initializer_list>
#include<vector>
#include<iostream>
#include"_DebugDelete.h"
#include<functional>

template<typename T> class Shared;

template<typename T> void swap(Shared<T>& p1, Shared<T>& p2);

template<typename T>
class Shared
{
public:
	Shared() :time(new size_t(1)), data(nullptr) {}
	//Shared(T d) :time(new size_t(1)), data(new T(d)) {} //普通构造函数
	Shared(T *d) :time(new size_t(1)), data(d) {} //重载普通构造函数
	Shared(const Shared &p); //拷贝构造函数
	~Shared(); //析构函数
	Shared<T> &operator= (const Shared &p);
	Shared(Shared &&p) noexcept; //移动构造函数
	Shared<T> &operator= (Shared &&p) noexcept ; //移动赋值运算符
public:
	friend void swap<T>(Shared<T> &p1, Shared<T> &p2);
	//T& operator *(const Shared &p) { return *p.data; }
	T& operator *() const { return *data; } //是类的成员函数，有一个隐式的this参数。 
	T* operator -> () const { return &this->operator *(); } //返回一个函数指针。
private:
	size_t *time;
	T *data;
	std::function<void(T*)> deleter { DebugDelete() }; //删除器
};
//拷贝构造函数
template<typename T>
Shared<T>::Shared(const Shared &p) 
{
	++*p.time;
	time = p.time;
	data = p.data;
	
}
//拷贝赋值运算
template<typename T>
Shared<T>& Shared<T>::operator=(const Shared & p)
{
	++*p.time;  //防止自赋值时的错误，应该先加后减。
	if (--*time == 0)
	{
		delete time;
		delete data;
	}
	time = p.time;
	data = p.data;
	return *this;
}
//析构函数
template<typename T>
Shared<T>::~Shared()
{
	if (*time == 0)
	{
		delete time;
		delete data;
	}
}

template<typename T> 
void swap(Shared<T>& p1, Shared<T>& p2)
{
	using std::swap;
	swap(p1.time, p2.time);
	swap(p1.data, p2.data);
}

//移动构造函数
template<typename T>
Shared<T>::Shared(Shared&& p) noexcept
{
	time = std::move(p.time);
	data = std::move(p.data);
	p.time = nullptr;
	p.data = nullptr;
}

//移动赋值运算符
template<typename T>
Shared<T> &Shared<T>::operator=(Shared &&p) noexcept
{
	/*if (this != &p)
	{
		if (--*time == 0)
		{
			delete time;
			delete data;
		}
		time = std::move(p.time);
		data = std::move(p.data);

	}
	return *this;*/
	if (--*time == 0)
	{
		delete time;
		delete data;
	}
	::swap(*this, p);
	return *this;
}


#endif

