#include "my_head.h"

std::allocator<std::string> StrVec::alloc;//在类中声明了static变量，在类外必须定义。

StrVec::StrVec(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	//cap = newdata.second;
	first_free = cap = newdata.second;
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc(); //确保有空间.
	alloc.construct(first_free++, s); //在first_free所指的位置构造s
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b,e,data) }; //第二个参数是拷贝b-e到地址data， 返回一个指针，指向最后一个元素之后的位置。

}

void StrVec::free()
{
	if (elements)
	{
		/*for (auto p = first_free; p != elements;)//first_free指向第一个空闲元素，即已有的对象的尾后位置.
		{
			alloc.destroy(--p);  //destroy销毁旧元素
		}*/
		for_each( elements,first_free, [](string &p) {alloc.destroy(&p); }); //用for_each 只需要给定范围和操作，不需要控制指针加减
		alloc.deallocate(elements, cap - elements);// deallocate收回已分配的空间
	}
}


StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second; //连续赋值...
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end()); //创造一个临时拷贝
	free();//清除原有空间
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  //如果原来的空间不为0，就申请一个原来空间两倍的新空间，否则申请一个大小为1的空间。
	auto newdata = alloc.allocate(newcapacity); //分配新内存
	auto dest = newdata; //新数组下一个空闲位置
	auto elem = elements; //旧数组下一个元素

	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++)); //将旧元素移动到新位置
	free(); //释放旧元素空间
			//更新数据结构。
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
