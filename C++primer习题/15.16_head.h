#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>

using namespace std;

class Quote
{
public:
	Quote() = default; //默认构造函数
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) {}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //返回给定数量的销售总额。 派生类改写折扣计算方法。

	virtual ~Quote() = default;

private:
	std::string bookNo; //书籍编号。

protected:
	double price = 0.0;  //不打折的价格
};

/*
class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Quote(book, sales_price), min_qty(max), discount(discount) {} //构造函数 ,首先初始化基类，然后按照声明顺序初始化派生类。

	 //double net_price(std::size_t n) const override{ return n*discount*price; } //派生类 虚函数。
	double net_price(std::size_t n) const override;

private:
	std::size_t min_qty = 0; //适用折扣的最低购买量
	double discount = 0.0; //折扣
};*/

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book,double sales_price, std::size_t max, const double discount):
		Quote(book,sales_price),quantity(max),discount(discount) {} //构造函数
	double net_price(std::size_t n) const = 0; //纯虚函数。这个类是抽象基类，无法创造这个类的对象。
	
protected: //如果声明成private ，则派生类无法访问，失去意义。
	std::size_t quantity = 0;  //适用折扣的购买量
	double discount = 0.0; //折扣
};

class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Disc_quote(book, sales_price, max, discount) {} 

	double net_price(std::size_t n) const override;
};
#endif