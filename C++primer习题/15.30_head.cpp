#include "my_head.h"

//bool Basket::compare(const std::shared_ptr<Quote> &lhs, const  std::shared_ptr<Quote> &rhs);
double print_total(ostream &os, std::shared_ptr<Quote> item, size_t n)
{
	double ret = item->net_price(n); //总收入
									 //os << "ISBN:" << item.isbn() << " #sold:" << n << " total due:" << ret << endl;
	return ret;

}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)
{
	Quote::operator=(rhs); //调用基类的拷贝赋值运算符。
	min_qty = rhs.min_qty;
	discount = rhs.discount;
	cout << "派生类拷贝赋值运算符" << endl;
	return *this;
}


Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs) noexcept
{
	Quote::operator=(rhs);//传入的参数是一个右值引用，所以调用的应该是基类的移动赋值运算符
	min_qty = std::move(rhs.min_qty);
	discount = std::move(rhs.discount);
	cout << "派生类移动赋值运算符" << endl;
	return *this;
}


double Bulk_quote::net_price(std::size_t n) const
{
	if (n <= min_qty)
		return n*price*discount;
	else
	{
		return min_qty*price*discount + (n - min_qty)*price;
	}
}

void Basket::add_item(const Quote &rhs)
{
	//items.insert(make_shared<Quote>(rhs)); //当rhs的动态类型不是Quote时，会出错
	//使用虚函数来解决动态绑定的问题.
	items.insert(shared_ptr<Quote> (rhs.clone()));
}
void Basket::add_item(Quote &&rhs)
{
	items.insert(shared_ptr<Quote> (rhs.clone()));
}

double Basket::total_receipt(std::ostream& os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) //跳转到不等于当前对象的下一个对象。
	{
		sum += print_total(os, *iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;

}
