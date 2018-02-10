#include "my_head.h"

std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	//cap = newdata.second;
	first_free = cap = newdata.second;
	cout << "��ʼ���б��캯��" << endl;
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
		for (auto p = first_free; p != elements;)//first_freeָ���һ������Ԫ�أ������еĶ����β��λ��.
		{
			alloc.destroy(--p);  //destroy���پ�Ԫ��
		}
		alloc.deallocate(elements, cap - elements);// deallocate�ջ��ѷ���Ŀռ�
	}
	cout << "�ͷ��ڴ�" << endl;
}


StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second; //������ֵ...
	cout << "�������캯��" << endl;
}
StrVec::~StrVec() { free(); cout << "��������" << endl; }
StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end()); //����һ����ʱ����
	free();//���ԭ�пռ�
	elements = data.first;
	first_free = cap = data.second;
	cout << "�������캯��" << endl;
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

void StrVec::resize(size_t n, const string & s = "")
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

StrVec::StrVec(StrVec && s) noexcept
{
	elements = s.elements;
	first_free = s.first_free;
	cap = s.cap;
	s.elements = s.first_free = s.cap = nullptr;
	cout << "�ƶ����캯��" << endl;
}

StrVec& StrVec::operator=(StrVec &&s) noexcept
{
	if (this != &s)
	{
		free(); //Ҫ�ͷ���������ڴ�
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	cout << "�ƶ���ֵ�����" << endl;
	return *this;
}