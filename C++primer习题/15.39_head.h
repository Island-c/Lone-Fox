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
	//拷贝控制成员： 
	TextQuery() :words(nullptr) {} //默认构造函数
	TextQuery(ifstream &in);
	TextQuery(const TextQuery &rhs) : words(new vector<string>(*(rhs.words))), word_No(rhs.word_No) { cout << "拷贝构造函数" << endl; } //拷贝构造函数
	TextQuery(TextQuery &&rhs) : words(new vector<string>(std::move(*(rhs.words)))), word_No(std::move(rhs.word_No))
	{
		rhs.words = nullptr;
		std::cout << "移动构造函数" << std::endl;
	} //移动构造函数。
	TextQuery& operator=(const TextQuery &rhs) //拷贝赋值运算符
	{
		words = make_shared<vector<string>>(*(rhs.words));
		word_No = rhs.word_No;
		cout << "拷贝赋值运算符" << endl;
		return *this;
	}
	TextQuery& operator=(TextQuery &&rhs) //移动赋值运算符
	{
		if (this != &rhs)
		{
			words = shared_ptr<vector<string>>(new vector<string>(std::move(*rhs.words)));
			word_No = std::move(rhs.word_No);
			rhs.words = nullptr;
		}
		cout << "移动赋值运算符" << endl;
		return *this;
	}

	~TextQuery() { cout << "析构函数" << endl; }



	QueryResult query(const string & word) const; //查找函数。

private:

	shared_ptr <vector<string>> words; //保存每行文本
	map<string, shared_ptr<set<lineNo>>> word_No; //每个单词 和对应的出现过它的行号的set.
};

class QueryResult
{
public:
	using ResultIter = std::set<TextQuery::lineNo>::iterator;
	friend std::ostream& print(std::ostream &out, const  QueryResult & word);
public:
	QueryResult(const std::string &s, std::shared_ptr<std::set<TextQuery::lineNo>> set, std::shared_ptr<std::vector<string>> v) :
		word(s), nos(set), input(v) { }
	
	shared_ptr<std::vector<std::string>> get_file() { return input; } //返回QueryResult中的文件。
	ResultIter begin() const { return nos->begin(); } //set的起始位置,返回类型是一个set的迭代器。
	std::set<TextQuery::lineNo>::iterator end() const { return nos->end(); } 

private:
	std::string word; //要查找的单词
	std::shared_ptr<std::set<TextQuery::lineNo>> nos; //该单词对应的行
	std::shared_ptr<std::vector<std::string>> input; //全部文本
};

//抽象基类，
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::lineNo;
	virtual ~Query_base() = default;

private:
	//eval返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery &) const = 0; 
	//rep表示查询的string
	virtual std::string rep() const = 0;

};
 
//给用户使用的类。
class Query //负责隐藏整个继承体系。
{
	//Query接受shared_ptr的构造函数是private的，所以要加友元。
	friend Query operator ~ (const Query &);
	friend Query operator | (const Query&, const Query &);
	friend Query operator & (const Query &, const Query &);

public:
	Query(const std::string &);
	
	//接口
	QueryResult eval(const TextQuery &t) const { return q->eval(t); } //虚函数。
	std::string rep() const { return q->rep(); }

private:
	//Query_base是一个基类指针，可以完成派生类到基类的转换。
	Query(std::shared_ptr<Query_base> query) :q(query){}  //接受智能指针的构造函数


	std::shared_ptr<Query_base> q;
};

class WordQuery :public Query_base
{
private:
	friend class Query;
	
	//构造函数
	WordQuery(const std::string &s):query_word(s) {}

	//虚函数
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word); 
	}
	std::string rep() const { return query_word; }
	
	std::string query_word;  //要查找的单词
};

class NotQuery :public Query_base  //~运算
{
private:
	friend Query operator~ (const Query &);
	//构造函数
	NotQuery(const Query &q) :query(q) {}
	//虚函数
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery &) const;
	//成员
	Query query;
};

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s):
		lhs(l),rhs(r),opSym(s) {}
	//不定义eval ,也是一个抽象基类
	std::string rep()const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }


	Query lhs, rhs; //左侧和右侧运算对象。
	std::string opSym; //运算符名字 &或者|
};

class AndQuery :public BinaryQuery // &运算
{

private:
	friend Query operator& (const Query &, const Query&);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}  //构造函数

	QueryResult eval(const TextQuery&) const;
};

class OrQuery :public BinaryQuery // |运算
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
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs)); //隐式的使用这个shared_ptr构造一个Query.
}

#endif
