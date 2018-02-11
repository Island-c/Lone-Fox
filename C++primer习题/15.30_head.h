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
	virtual Quote* clone()const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); } //������ֵ���ã�ֻ��Ҫ�ӹ���ռ伴��

private:
	std::string bookNo; //�鼮��š�

protected:
	double price = 0.0;  //�����۵ļ۸�
};

class Bulk_quote : public Quote
{
public:
	using Quote::Quote; //�̳л���Ĺ��캯��.
	Bulk_quote(const Bulk_quote& rhs) :Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "�����࿽�����캯��" << endl; }
	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount))
	{
		cout << "�������ƶ����캯��" << endl;
	}
	Bulk_quote& operator = (const Bulk_quote & rhs);

	Bulk_quote& operator= (Bulk_quote&& rhs)noexcept;

	~Bulk_quote() override { cout << "��������������" << endl; }


public:
	Bulk_quote() { cout << "������Ĭ�Ϲ��캯��" << endl; }
	Bulk_quote(const std::string &book, double sales_price, std::size_t max, const double discount)
		:Quote(book, sales_price), min_qty(max), discount(discount) {
		cout << "��������ͨ���캯��" << endl;
	} //���캯�� ,���ȳ�ʼ�����࣬Ȼ��������˳���ʼ�������ࡣ

	  //double net_price(std::size_t n) const override{ return n*discount*price; } //������ �麯����
	double net_price(std::size_t n) const override;
	Bulk_quote* clone()const & override{ return new Bulk_quote(*this); }
	Bulk_quote* clone() && override{return new Bulk_quote(std::move(*this)); } 
	void debug() const override { Quote::debug();  std::cout << "min_qtr: " << min_qty << "   " << "discount" << discount << std::endl; }
private:
	std::size_t min_qty = 0; //�����ۿ۵���͹�����
	double discount = 0.0; //�ۿ�
};


class Basket //������
{
public:
	// ʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
	void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
	void add_item(const Quote &);
	void add_item(Quote &&);
	//��ӡÿ������ܼۺ͹��������ܼ�
	double total_receipt(std::ostream&) const;


private:
	//���ڱȽ�shared_ptr�ĺ���
	static bool Basket::compare(const std::shared_ptr<Quote> &lhs, const  std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }

	//multiset������Quote�� ��compare����
	//��ʹ��decltype�����һ������ָ������ʱ���������*ָ��Ҫʹ��һ�������������͵�ָ�롣
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

};


double print_total(ostream &os, std::shared_ptr<Quote> item, size_t n);


#endif