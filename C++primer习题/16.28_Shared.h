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
	//Shared(T d) :time(new size_t(1)), data(new T(d)) {} //��ͨ���캯��
	Shared(T *d) :time(new size_t(1)), data(d) {} //������ͨ���캯��
	Shared(const Shared &p); //�������캯��
	~Shared(); //��������
	Shared<T> &operator= (const Shared &p);
	Shared(Shared &&p) noexcept; //�ƶ����캯��
	Shared<T> &operator= (Shared &&p) noexcept ; //�ƶ���ֵ�����
public:
	friend void swap<T>(Shared<T> &p1, Shared<T> &p2);
	//T& operator *(const Shared &p) { return *p.data; }
	T& operator *() const { return *data; } //����ĳ�Ա��������һ����ʽ��this������ 
	T* operator -> () const { return &this->operator *(); } //����һ������ָ�롣
private:
	size_t *time;
	T *data;
	std::function<void(T*)> deleter { DebugDelete() }; //ɾ����
};
//�������캯��
template<typename T>
Shared<T>::Shared(const Shared &p) 
{
	++*p.time;
	time = p.time;
	data = p.data;
	
}
//������ֵ����
template<typename T>
Shared<T>& Shared<T>::operator=(const Shared & p)
{
	++*p.time;  //��ֹ�Ը�ֵʱ�Ĵ���Ӧ���ȼӺ����
	if (--*time == 0)
	{
		delete time;
		delete data;
	}
	time = p.time;
	data = p.data;
	return *this;
}
//��������
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

//�ƶ����캯��
template<typename T>
Shared<T>::Shared(Shared&& p) noexcept
{
	time = std::move(p.time);
	data = std::move(p.data);
	p.time = nullptr;
	p.data = nullptr;
}

//�ƶ���ֵ�����
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

