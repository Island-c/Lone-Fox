#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>

using namespace std;

class Quote
{
public:
	Quote() = default; //Ĭ�Ϲ��캯��
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) {}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //���ظ��������������ܶ �������д�ۿۼ��㷽����

	virtual ~Quote() = default;

private:
	std::string bookNo; //�鼮��š�

protected:
	double price = 0.0;  //�����۵ļ۸�
};

/*
class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Quote(book, sales_price), min_qty(max), discount(discount) {} //���캯�� ,���ȳ�ʼ�����࣬Ȼ��������˳���ʼ�������ࡣ

	 //double net_price(std::size_t n) const override{ return n*discount*price; } //������ �麯����
	double net_price(std::size_t n) const override;

private:
	std::size_t min_qty = 0; //�����ۿ۵���͹�����
	double discount = 0.0; //�ۿ�
};*/

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book,double sales_price, std::size_t max, const double discount):
		Quote(book,sales_price),quantity(max),discount(discount) {} //���캯��
	double net_price(std::size_t n) const = 0; //���麯����������ǳ�����࣬�޷����������Ķ���
	
protected: //���������private �����������޷����ʣ�ʧȥ���塣
	std::size_t quantity = 0;  //�����ۿ۵Ĺ�����
	double discount = 0.0; //�ۿ�
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