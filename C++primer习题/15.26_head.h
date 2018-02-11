#ifndef QUOTE_H
#define QUOTE_H

#include<string>
#include<iostream>
using namespace std;

class Quote
{
public:
	Quote(const Quote& rhs) :bookNo(rhs.bookNo), price(rhs.price) { cout << "基类拷贝构造函数" << endl; }
	Quote(Quote &&rhs)noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) { cout << "基类移动构造函数" << endl; }
	Quote& operator= (const Quote& rhs)
	{
		cout << "基类拷贝赋值运算符" << endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote& operator=(Quote && rhs) noexcept
	{
		cout << "基类移动赋值运算符" << endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	virtual ~Quote() { cout << "基类析构函数" << endl; }


public:
	Quote() { cout << "基类默认构造函数" << endl; } //默认构造函数
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) { cout << "基类普通构造函数" << endl; }

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //返回给定数量的销售总额。 派生类改写折扣计算方法。
	virtual void debug() const { std::cout << "bookNo: " << bookNo << "   " << "price: " << price << std::endl; }
	

private:
	std::string bookNo; //书籍编号。

protected:
	double price = 0.0;  //不打折的价格
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote(const Bulk_quote& rhs) :Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "派生类拷贝构造函数" << endl; }
	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) 
		{ cout << "派生类移动构造函数" << endl; }
	Bulk_quote& operator = (const Bulk_quote & rhs)
	{
		Quote::operator=(rhs); //调用基类的拷贝赋值运算符。
		min_qty=rhs.min_qty; 
		discount=rhs.discount;
		cout << "派生类拷贝赋值运算符" << endl;
		return *this;
	}
	Bulk_quote& operator= (Bulk_quote&& rhs)noexcept
	{
		Quote::operator=(rhs);//传入的参数是一个右值引用，所以调用的应该是基类的移动赋值运算符
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		cout << "派生类移动赋值运算符" << endl;
		return *this;
	}
	~Bulk_quote() override{ cout << "派生类析构函数" << endl; }


public:
	Bulk_quote() { cout << "派生类默认构造函数" << endl; }
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Quote(book, sales_price), min_qty(max), discount(discount) {
		cout << "派生类普通构造函数" << endl;
	} //构造函数 ,首先初始化基类，然后按照声明顺序初始化派生类。

																	   //double net_price(std::size_t n) const override{ return n*discount*price; } //派生类 虚函数。
	double net_price(std::size_t n) const override;

	void debug() const override { Quote::debug();  std::cout << "min_qtr: " << min_qty << "   " << "discount" << discount << std::endl; }
private:
	std::size_t min_qty = 0; //适用折扣的最低购买量
	double discount = 0.0; //折扣
};



#endif