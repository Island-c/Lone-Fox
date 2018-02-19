#ifndef MY_HEAD_H
#define MY_HEAD_H
#include <initializer_list>
#include<vector>
#include<iostream>
#include<memory>
template <typename> class BlobPtr;
template <typename>  class Blob;
template <typename T>
bool operator == (const Blob<T>&, const Blob<T>&);

template <typename T> class Blob
{


public:
	friend class BlobPtr<T>;
	friend bool operator ==<T> (const Blob<T>&, const Blob<T> &); //һ��һ�Ѻù�ϵ�� ��Ϊ��ʹ����Ӧ���͵�==���㹻�ˡ�

	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	//���캯��
	Blob();
	Blob(std::initializer_list<T> il);
	template<typename IT> Blob(IT iter1, IT iter2);

	//Ԫ����Ŀ
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//��Ӻ�ɾ��Ԫ��
	void push_back(T &&t) { data->push_back(t); }//ʹ����ֵ����
	void pop_back();

	//Ԫ�ط��� ,����������Ԫ�ص����á�
	T& back();
	T& operator[] (size_type i);


private:
	std::shared_ptr<std::vector<T>> data;

	void check(size_type i, const std::string &msg) const;

};

template <typename T>
bool operator == (const Blob<T> &lhs, const Blob<T> &rhs)
{
	return *(lhs.data) == *(rhs.data);
	//return lhs->data = rhs->data;
	//����1. lhs��rhs����Blob���͵ģ����ǵĳ�Աdata����һ��ָ�롣 2. �ж��Ƿ����ʹ��== ������ =
}


template<typename T>
Blob<T>::Blob() :data(std::make_shared<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template<typename T>
template<typename IT>
Blob<T>::Blob(IT iter1, IT iter2)  //���������������Ĺ��캯��
{
	data = std::make_shared<std::vector<T>>(iter1, iter2);
}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range ");
	return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}



template<typename T> class BlobPtr
{
public:
	typedef typename std::vector<T>::size_type size_type;
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	T& deref() const;
	BlobPtr& incr(); //����ǰ׺�� ������������ڣ�����Ҫ����ʽģ��ʵ��

private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &msg) const;
	std::weak_ptr <std::vector<T> > wptr;
	std::size_t curr;

};

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock(); //���vector�ǲ��ǻ�����...����ֵ��һ��shared_ptr�� ��Ϊ����ָ��wptr��ָ��vector<T>
	if (!ret)
		throw std::runtime_error("unbound BolbPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}


template<typename T>
T& BlobPtr<T>::deref() const
{
	auto p = check(curr, "dereference pastend");
	return (*p)[curr];
}


template<typename T>
BlobPtr<T>& BlobPtr<T>::incr()
{
	check(curr, "increment past end of BlobPtr");
	curr++;
	return *this;
}
#endif

