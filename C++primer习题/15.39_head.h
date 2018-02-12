#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<sstream>
#include<iterator>
#include<algorithm>
using namespace std;

class QueryResult;
class TextQuery
{
public:

	using lineNo = vector<string>::size_type;
	//�������Ƴ�Ա�� 
	TextQuery() :words(nullptr) {} //Ĭ�Ϲ��캯��
	TextQuery(ifstream &in);
	TextQuery(const TextQuery &rhs) : words(new vector<string>(*(rhs.words))), word_No(rhs.word_No) { cout << "�������캯��" << endl; } //�������캯��
	TextQuery(TextQuery &&rhs) : words(new vector<string>(std::move(*(rhs.words)))), word_No(std::move(rhs.word_No))
	{
		rhs.words = nullptr;
		std::cout << "�ƶ����캯��" << std::endl;
	} //�ƶ����캯����
	TextQuery& operator=(const TextQuery &rhs) //������ֵ�����
	{
		words = make_shared<vector<string>>(*(rhs.words));
		word_No = rhs.word_No;
		cout << "������ֵ�����" << endl;
		return *this;
	}
	TextQuery& operator=(TextQuery &&rhs) //�ƶ���ֵ�����
	{
		if (this != &rhs)
		{
			words = shared_ptr<vector<string>>(new vector<string>(std::move(*rhs.words)));
			word_No = std::move(rhs.word_No);
			rhs.words = nullptr;
		}
		cout << "�ƶ���ֵ�����" << endl;
		return *this;
	}

	~TextQuery() { cout << "��������" << endl; }



	QueryResult query(const string & word) const; //���Һ�����

private:

	shared_ptr <vector<string>> words; //����ÿ���ı�
	map<string, shared_ptr<set<lineNo>>> word_No; //ÿ������ �Ͷ�Ӧ�ĳ��ֹ������кŵ�set.
};

class QueryResult
{
public:
	using ResultIter = std::set<TextQuery::lineNo>::iterator;
	friend std::ostream& print(std::ostream &out, const  QueryResult & word);
public:
	QueryResult(const std::string &s, std::shared_ptr<std::set<TextQuery::lineNo>> set, std::shared_ptr<std::vector<string>> v) :
		word(s), nos(set), input(v) { }
	
	shared_ptr<std::vector<std::string>> get_file() { return input; } //����QueryResult�е��ļ���
	ResultIter begin() const { return nos->begin(); } //set����ʼλ��,����������һ��set�ĵ�������
	std::set<TextQuery::lineNo>::iterator end() const { return nos->end(); } 

private:
	std::string word; //Ҫ���ҵĵ���
	std::shared_ptr<std::set<TextQuery::lineNo>> nos; //�õ��ʶ�Ӧ����
	std::shared_ptr<std::vector<std::string>> input; //ȫ���ı�
};

//������࣬
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::lineNo;
	virtual ~Query_base() = default;

private:
	//eval�����뵱ǰQueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery &) const = 0; 
	//rep��ʾ��ѯ��string
	virtual std::string rep() const = 0;

};
 
//���û�ʹ�õ��ࡣ
class Query //�������������̳���ϵ��
{
	//Query����shared_ptr�Ĺ��캯����private�ģ�����Ҫ����Ԫ��
	friend Query operator ~ (const Query &);
	friend Query operator | (const Query&, const Query &);
	friend Query operator & (const Query &, const Query &);

public:
	Query(const std::string &);
	
	//�ӿ�
	QueryResult eval(const TextQuery &t) const { return q->eval(t); } //�麯����
	std::string rep() const { return q->rep(); }

private:
	//Query_base��һ������ָ�룬������������ൽ�����ת����
	Query(std::shared_ptr<Query_base> query) :q(query){}  //��������ָ��Ĺ��캯��


	std::shared_ptr<Query_base> q;
};

class WordQuery :public Query_base
{
private:
	friend class Query;
	
	//���캯��
	WordQuery(const std::string &s):query_word(s) {}

	//�麯��
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word); 
	}
	std::string rep() const { return query_word; }
	
	std::string query_word;  //Ҫ���ҵĵ���
};

class NotQuery :public Query_base  //~����
{
private:
	friend Query operator~ (const Query &);
	//���캯��
	NotQuery(const Query &q) :query(q) {}
	//�麯��
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery &) const;
	//��Ա
	Query query;
};

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s):
		lhs(l),rhs(r),opSym(s) {}
	//������eval ,Ҳ��һ���������
	std::string rep()const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }


	Query lhs, rhs; //�����Ҳ��������
	std::string opSym; //��������� &����|
};

class AndQuery :public BinaryQuery // &����
{

private:
	friend Query operator& (const Query &, const Query&);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}  //���캯��

	QueryResult eval(const TextQuery&) const;
};

class OrQuery :public BinaryQuery // |����
{
private:
	friend Query operator | (const Query &, const Query&);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {} 

	QueryResult eval(const TextQuery&) const;
};

inline Query::Query(const std::string &s)
{
	q = shared_ptr<Query_base>(new WordQuery(s));
}

inline Query operator~ (const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator& (const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator | (const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs)); //��ʽ��ʹ�����shared_ptr����һ��Query.
}

#endif
