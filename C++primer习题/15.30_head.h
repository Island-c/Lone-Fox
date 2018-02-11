#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>
#include<memory>
#include<set>
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
	virtual Quote* clone()const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); } //对于右值引用，只需要接管其空间即可

private:
	std::string bookNo; //书籍编号。

protected:
	double price = 0.0;  //不打折的价格
};

class Bulk_quote : public Quote
{
public:
	using Quote::Quote; //继承基类的构造函数.
	Bulk_quote(const Bulk_quote& rhs) :Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "派生类拷贝构造函数" << endl; }
	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount))
	{
		cout << "派生类移动构造函数" << endl;
	}
	Bulk_quote& operator = (const Bulk_quote & rhs);

	Bulk_quote& operator= (Bulk_quote&& rhs)noexcept;

	~Bulk_quote() override { cout << "派生类析构函数" << endl; }


public:
	Bulk_quote() { cout << "派生类默认构造函数" << endl; }
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Quote(book, sales_price), min_qty(max), discount(discount) {
		cout << "派生类普通构造函数" << endl;
	} //构造函数 ,首先初始化基类，然后按照声明顺序初始化派生类。

	  //double net_price(std::size_t n) const override{ return n*discount*price; } //派生类 虚函数。
	double net_price(std::size_t n) const override;
	Bulk_quote* clone()const & override{ return new Bulk_quote(*this); }
	Bulk_quote* clone() && override{return new Bulk_quote(std::move(*this)); } 
	void debug() const override { Quote::debug();  std::cout << "min_qtr: " << min_qty << "   " << "discount" << discount << std::endl; }
private:
	std::size_t min_qty = 0; //适用折扣的最低购买量
	double discount = 0.0; //折扣
};


class Basket //购物篮
{
public:
	// 使用合成的默认构造函数和拷贝控制成员
	void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
	void add_item(const Quote &);
	void add_item(Quote &&);
	//打印每本书的总价和购物篮的总价
	double total_receipt(std::ostream&) const;


private:
	//用于比较shared_ptr的函数
	static bool Basket::compare(const std::shared_ptr<Quote> &lhs, const  std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }

	//multiset保存多个Quote， 按compare排序
	//当使用decltype来获得一个函数指针类型时，必须加上*指出要使用一个给定函数类型的指针。
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

};


double print_total(ostream &os, std::shared_ptr<Quote> item, size_t n);


#endif