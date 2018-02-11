#include "my_head.h"

//bool Basket::compare(const std::shared_ptr<Quote> &lhs, const  std::shared_ptr<Quote> &rhs);
double print_total(ostream &os, std::shared_ptr<Quote> item, size_t n)
{
	double ret = item->net_price(n); //������
									 //os << "ISBN:" << item.isbn() << " #sold:" << n << " total due:" << ret << endl;
	return ret;

}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)
{
	Quote::operator=(rhs); //���û���Ŀ�����ֵ�������
	min_qty = rhs.min_qty;
	discount = rhs.discount;
	cout << "�����࿽����ֵ�����" << endl;
	return *this;
}


Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs) noexcept
{
	Quote::operator=(rhs);//����Ĳ�����һ����ֵ���ã����Ե��õ�Ӧ���ǻ�����ƶ���ֵ�����
	min_qty = std::move(rhs.min_qty);
	discount = std::move(rhs.discount);
	cout << "�������ƶ���ֵ�����" << endl;
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
	//items.insert(make_shared<Quote>(rhs)); //��rhs�Ķ�̬���Ͳ���Quoteʱ�������
	//ʹ���麯���������̬�󶨵�����.
	items.insert(shared_ptr<Quote> (rhs.clone()));
}
void Basket::add_item(Quote &&rhs)
{
	items.insert(shared_ptr<Quote> (rhs.clone()));
}

double Basket::total_receipt(std::ostream& os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) //��ת�������ڵ�ǰ�������һ������
	{
		sum += print_total(os, *iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;

}
