#ifndef MY_HEAD_H
#define MY_HEAD_H



#include<string>

using namespace std;

class Quote
{
public:
	Quote() = default; //Ĭ�Ϲ��캯��
	Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //���ظ��������������ܶ �������д�ۿۼ��㷽����

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
	Bulk_quote(const std::string &book, double sales_price,std::size_t n,const double discount)
		:Quote(book,sales_price),min_qty(n),discount(discount) {} //���캯�� ,���ȳ�ʼ�����࣬Ȼ��������˳���ʼ�������ࡣ

	double net_price(std::size_t n) const override{ return n*discount*price; } //������ �麯����

private:
	std::size_t min_qty = 0; //�����ۿ۵���͹�����
	double discount = 0.0; //�ۿ�
};

#endif