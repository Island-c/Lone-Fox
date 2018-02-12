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
#include<algorithm>
using namespace std;

class QueryResult;
class TextQuery
{
public:	
	
	using lineNo = vector<string>::size_type;
	//拷贝控制成员： 
	TextQuery():words(nullptr){} //默认构造函数
	TextQuery(ifstream &in);
	TextQuery(const TextQuery &rhs) : words(new vector<string>(*(rhs.words))), word_No(rhs.word_No) { cout << "拷贝构造函数" << endl; } //拷贝构造函数
	TextQuery(TextQuery &&rhs) : words(new vector<string>(std::move(*(rhs.words)))), word_No(std::move(rhs.word_No))
	{
		rhs.words = nullptr; 
		std::cout << "移动构造函数" << std::endl;
	} //移动构造函数。
	TextQuery& operator=(const TextQuery &rhs) //拷贝赋值运算符
	{
		words = make_shared<vector<string>> (*(rhs.words));
		word_No = rhs.word_No;
		cout << "拷贝赋值运算符" << endl;
		return *this;
	}
	TextQuery& operator=( TextQuery &&rhs) //移动赋值运算符
	{
		if (this != &rhs)
		{
			words = shared_ptr<vector<string>> (new vector<string>(std::move(*rhs.words)));
			word_No=std::move(rhs.word_No);
			rhs.words = nullptr;
		}
		cout << "移动赋值运算符" << endl;
		return *this;
	}

	~TextQuery() { cout << "析构函数" << endl; }
	

	
	QueryResult query(const string & word); //查找函数。

private:

	shared_ptr <vector<string>> words; //保存每行文本
	map<string, shared_ptr<set<lineNo>>> word_No; //每个单词 和对应的出现过它的行号的set.
};


class QueryResult
{
public:
	friend std::ostream& print(std::ostream &out, const  QueryResult & word);
public:
	QueryResult(const std::string &s, std::shared_ptr<std::set<TextQuery::lineNo>> set, std::shared_ptr<std::vector<string>> v) :
		word(s), nos(set), input(v) { }

private:
	std::string word; //要查找的单词
	std::shared_ptr<std::set<TextQuery::lineNo>> nos; //该单词对应的行
	std::shared_ptr<std::vector<std::string>> input; //全部文本
};



#endif
