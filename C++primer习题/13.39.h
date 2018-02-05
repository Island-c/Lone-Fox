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
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){} //���캯��
	StrVec(initializer_list<string> il);
	StrVec(const StrVec&);  //�������캯��
	StrVec& operator =(const StrVec&); //������ֵ�����
	~StrVec(); //��������

public:
	void push_back(const std::string&); //���Ԫ��
	size_t size() const { return first_free - elements; } //��ռ�ÿռ��С
	size_t capacity()const { return cap - elements; } //�ܿռ��С
	void reverse(size_t n) { if (n > capacity()) reallocate(); };  //����ռ䲻���ã������·���ռ䡣
	void resize(size_t);
	void resize(size_t, const std::string &);
	

	std::string *begin() const { return elements; }
	std::string *end()const { return first_free; }


private:
	static std::allocator<std::string> alloc; //����Ԫ��
	// �����Ԫ�صĺ���ʹ��
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate(); //ȷ�����㹻�Ŀռ�
	}
	//���ߺ��������������캯������ֵ�����������������ʹ�á�
	std::pair<std::string*, std::string *> alloc_n_copy(const std::string*, const std::string*);
	void free(); //����Ԫ�� �ͷ��ڴ�
	void reallocate(); //��ø���ռ䲢�������к���
	//���ݳ�Ա
	std::string *elements;  //��Ԫ��
	std::string *first_free; //��һ������Ԫ��
	std::string *cap;  //β��λ��

};


#endif
