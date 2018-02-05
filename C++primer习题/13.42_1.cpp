#include "my_head.h"

std::allocator<std::string> StrVec::alloc;//������������static��������������붨�塣

StrVec::StrVec(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	//cap = newdata.second;
	first_free = cap = newdata.second;
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc(); //ȷ���пռ�.
	alloc.construct(first_free++, s); //��first_free��ָ��λ�ù���s
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b,e,data) }; //�ڶ��������ǿ���b-e����ַdata�� ����һ��ָ�룬ָ�����һ��Ԫ��֮���λ�á�

}

void StrVec::free()
{
	if (elements)
	{
		/*for (auto p = first_free; p != elements;)//first_freeָ���һ������Ԫ�أ������еĶ����β��λ��.
		{
			alloc.destroy(--p);  //destroy���پ�Ԫ��
		}*/
		for_each( elements,first_free, [](string &p) {alloc.destroy(&p); }); //��for_each ֻ��Ҫ������Χ�Ͳ���������Ҫ����ָ��Ӽ�
		alloc.deallocate(elements, cap - elements);// deallocate�ջ��ѷ���Ŀռ�
	}
}


StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second; //������ֵ...
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end()); //����һ����ʱ����
	free();//���ԭ�пռ�
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  //���ԭ���Ŀռ䲻Ϊ0��������һ��ԭ���ռ��������¿ռ䣬��������һ����СΪ1�Ŀռ䡣
	auto newdata = alloc.allocate(newcapacity); //�������ڴ�
	auto dest = newdata; //��������һ������λ��
	auto elem = elements; //��������һ��Ԫ��

	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++)); //����Ԫ���ƶ�����λ��
	free(); //�ͷž�Ԫ�ؿռ�
			//�������ݽṹ��
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;

}



void StrVec::resize(size_t n,const string & s="") 
{
	if (n > size())
	{
		while (size() < n)
		{
			push_back(s);
		}
	}
	else if (n < size())
	{
		while (size() > n)
		{
			alloc.destroy(--first_free); 
		}
	}
}
