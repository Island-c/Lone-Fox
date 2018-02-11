#ifndef QUOTE_H
#define QUOTE_H

#include<string>
#include<iostream>
using namespace std;

class Quote
{
public:
	Quote(const Quote& rhs) :bookNo(rhs.bookNo), price(rhs.price) { cout << "���࿽�����캯��" << endl; }
	Quote(Quote &&rhs)noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) { cout << "�����ƶ����캯��" << endl; }
	Quote& operator= (const Quote& rhs)
	{
		cout << "���࿽����ֵ�����" << endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote& operator=(Quote && rhs) noexcept
	{
		cout << "�����ƶ���ֵ�����" << endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	virtual ~Quote() { cout << "������������" << endl; }


public:
	Quote() { cout << "����Ĭ�Ϲ��캯��" << endl; } //Ĭ�Ϲ��캯��
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) { cout << "������ͨ���캯��" << endl; }

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; } //���ظ��������������ܶ �������д�ۿۼ��㷽����
	virtual void debug() const { std::cout << "bookNo: " << bookNo << "   " << "price: " << price << std::endl; }
	

private:
	std::string bookNo; //�鼮��š�

protected:
	double price = 0.0;  //�����۵ļ۸�
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote(const Bulk_quote& rhs) :Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "�����࿽�����캯��" << endl; }
	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) 
		{ cout << "�������ƶ����캯��" << endl; }
	Bulk_quote& operator = (const Bulk_quote & rhs)
	{
		Quote::operator=(rhs); //���û���Ŀ�����ֵ�������
		min_qty=rhs.min_qty; 
		discount=rhs.discount;
		cout << "�����࿽����ֵ�����" << endl;
		return *this;
	}
	Bulk_quote& operator= (Bulk_quote&& rhs)noexcept
	{
		Quote::operator=(rhs);//����Ĳ�����һ����ֵ���ã����Ե��õ�Ӧ���ǻ�����ƶ���ֵ�����
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		cout << "�������ƶ���ֵ�����" << endl;
		return *this;
	}
	~Bulk_quote() override{ cout << "��������������" << endl; }


public:
	Bulk_quote() { cout << "������Ĭ�Ϲ��캯��" << endl; }
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Quote(book, sales_price), min_qty(max), discount(discount) {
		cout << "��������ͨ���캯��" << endl;
	} //���캯�� ,���ȳ�ʼ�����࣬Ȼ��������˳���ʼ�������ࡣ

																	   //double net_price(std::size_t n) const override{ return n*discount*price; } //������ �麯����
	double net_price(std::size_t n) const override;

	void debug() const override { Quote::debug();  std::cout << "min_qtr: " << min_qty << "   " << "discount" << discount << std::endl; }
private:
	std::size_t min_qty = 0; //�����ۿ۵���͹�����
	double discount = 0.0; //�ۿ�
};



#endif