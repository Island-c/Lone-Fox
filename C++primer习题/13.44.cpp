#include "my_head.h"

std::allocator<char> String::alloc; //��������alloc�����ĸ��࣡

pair<char *, char *>  String::alloc_n_copy(const char *l, const char *r) // ����ռ䡣
{
	auto newdata=alloc.allocate(r - l);

	return { newdata, uninitialized_copy(l,r,newdata) };
}
void String::range_build(const char* l, const char* r) //������Ա������������ͬ�Ĳ���������д��һ������������
{
	auto newString = alloc_n_copy(l, r);
	elements = newString.first;
	end = newString.second;
}

void String::free() //����Ԫ�غ��ջؿռ�
{
	if (elements) //elements���� nullptr
	{
		std::for_each(elements, end, [](char &r) {alloc.destroy(&r); });  //ɾ������ռ��е�ÿ��Ԫ��
		alloc.deallocate(elements, end-elements);  //�ջط���Ŀռ�
	}

}


String::String(const char * c) //���캯��
{
	//char* s1 = const_cast<char*> (c);  //ǿ������ת����ȥconst �� �����ܸ�ֵ��
	const char *s1 = c;
	while (*s1) ++s1;
	range_build(c, s1);
}

String::String(const String& s)
{
	/*auto newStr = alloc_n_copy(s.elements, s.end);
	//free(); //�������캯������Ҫfree�ڴ棬��Ϊִ����������ģ����ǵ�һ�ζ���Ķ���
	elements = newStr.first;
	end = newStr.second;*/
	range_build(s.elements, s.end);
}

String& String::operator= (const String & s) //������ֵ������� Ҫfree���Ķ���.
{
	auto newStr = alloc_n_copy(s.elements, s.end);
	free();
	elements = newStr.first;
	end = newStr.second;
	return *this;
}

String::~String()
{
	free();
}