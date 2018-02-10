#include "my_head.h"

std::allocator<char> String::alloc; //��������alloc�����ĸ��࣡

pair<char *, char *>  String::alloc_n_copy(const char *l, const char *r) // ����ռ䡣
{
	auto newdata=alloc.allocate(r - l); //����ռ�

	return { newdata, uninitialized_copy(l,r,newdata) }; //��������
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
	cout << "��ͨ���캯��" << endl;
}

String::String(const String& s)
{
	/*auto newStr = alloc_n_copy(s.elements, s.end);
	//free(); //�������캯������Ҫfree�ڴ棬��Ϊִ����������ģ����ǵ�һ�ζ���Ķ���
	elements = newStr.first;
	end = newStr.second;*/
	range_build(s.elements, s.end);
	cout << "�������캯��" << endl;
}

String::String(String && s)
{
	range_build(std::move(s.elements), std::move(s.end));
	cout << "�ƶ����캯��" << endl;

}
String& String::operator=(String && s)
{
	auto newStr = alloc_n_copy(std::move(s.elements), std::move(s.end));
	free();
	elements = newStr.first;
	end = newStr.second;
	cout << "�ƶ���ֵ�����" << endl;
	return *this;


}

String& String::operator= (const String & s) //������ֵ������� Ҫfree���Ķ���.
{
	auto newStr = alloc_n_copy(s.elements, s.end);
	free();
	elements = newStr.first;
	end = newStr.second;
	cout << "������ֵ�����" << endl;
	return *this;
}

String::~String()
{
	cout << "��������" << endl;
	free();
}