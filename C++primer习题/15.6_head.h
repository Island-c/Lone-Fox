#ifndef MY_HEAD_H
#define MY_HEAD_H



#include<string>

using namespace std;

class Quote
{
public:
	Quote() = default; //默认构造函数
	Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //返回给定数量的销售总额。 派生类改写折扣计算方法。

	virtual ~Quote() = default;

private:
	std::string bookNo; //书籍编号。

protected:
	double price = 0.0;  //不打折的价格
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price,std::size_t n,const double discount)
		:Quote(book,sales_price),min_qty(n),discount(discount) {} //构造函数 ,首先初始化基类，然后按照声明顺序初始化派生类。

	double net_price(std::size_t n) const override{ return n*discount*price; } //派生类 虚函数。

private:
	std::size_t min_qty = 0; //适用折扣的最低购买量
	double discount = 0.0; //折扣
};

#endif