#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>
#include<iostream>
using namespace std;

class Quote
{
public:
	Quote() = default; //Ĭ�Ϲ��캯��
	Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //���ظ��������������ܶ �������д�ۿۼ��㷽����
	virtual void debug() const { std::cout << "bookNo: " << bookNo << "   " << "price: " << price << std::endl; }
	virtual ~Quote() = default;

private:
	std::string bookNo; //�鼮��š�

protected:
	double price = 0.0;  //�����۵ļ۸�
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price,std::size_t max,const double discount)
		:Quote(book,sales_price),min_qty(max),discount(discount) {} //���캯�� ,���ȳ�ʼ�����࣬Ȼ��������˳���ʼ�������ࡣ

	//double net_price(std::size_t n) const override{ return n*discount*price; } //������ �麯����
	double net_price(std::size_t n) const override; 
	void debug() const override { Quote::debug();  std::cout << "min_qtr: " << min_qty << "   " << "discount" << discount << std::endl; }
private:
	std::size_t min_qty = 0; //�����ۿ۵���͹�����
	double discount = 0.0; //�ۿ�
};

#endif